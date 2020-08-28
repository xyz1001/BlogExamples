//
// Created by xyz1001 on 20-8-27.
//

#include "system_info.h"

#include <cassert>
#include <memory>

#include "global.h"

namespace {
static jclass gClazz = nullptr;
}

SystemInfo::SystemInfo() {
    JNIEnv *env;
    GetJVM()->AttachCurrentThread(&env, nullptr);
    assert(env);
    // AttachCurrentThread得到的env需要使用DetachCurrentThread进行脱离，
    // 这里使用RAII来实现这一点
    std::shared_ptr<void> guard(nullptr, [env](void *){
        GetJVM()->DetachCurrentThread();
    });

    // 获取构造函数ID，函数名固定为<init>，注意返回值类型为V，即void
    jmethodID id = env->GetMethodID(gClazz, "<init>", "()V");
    assert(id);
    jobject jsystem_info = env->NewObject(gClazz, id);
    object_ = env->NewGlobalRef(jsystem_info);
}

SystemInfo::~SystemInfo() {
    JNIEnv *env;
    GetJVM()->AttachCurrentThread(&env, nullptr);
    assert(env);
    std::shared_ptr<void> guard(nullptr, [env](void *){
        GetJVM()->DetachCurrentThread();
    });

    env->DeleteGlobalRef(object_);
}


std::string SystemInfo::GetOsVersion() const {
    JNIEnv *env;
    GetJVM()->AttachCurrentThread(&env, nullptr);
    assert(env);
    std::shared_ptr<void> env_guard(nullptr, [env](void *){
        GetJVM()->DetachCurrentThread();
    });

    // 这里的函数签名纯手写非常麻烦，建议通过Android Studio自动补全
    jmethodID method = env->GetMethodID(gClazz, "getOsVersion", "()Ljava/lang/String;");
    assert(method);
    jstring jver = static_cast<jstring>(env->CallObjectMethod(object_, method));

    // 将jstring转换为std::string
    const char *ver = env->GetStringUTFChars(jver, 0);
    std::shared_ptr<const char> os_version_guard(ver, [&env, &jver](const char *ver) {
        env->ReleaseStringUTFChars(jver, ver);
    });

    return std::string(ver);
}

int SystemInfo::GetApiLevel() const {
    JNIEnv *env;
    GetJVM()->AttachCurrentThread(&env, nullptr);
    assert(env);
    std::shared_ptr<void> env_guard(nullptr, [env](void *){
        GetJVM()->DetachCurrentThread();
    });

    // 这里的函数签名纯手写非常麻烦，建议通过Android Studio自动补全
    jmethodID method = env->GetMethodID(gClazz, "getApiLevel", "()I");
    assert(method);
    return static_cast<int>(env->CallIntMethod(object_, method));
}

void SystemInfo::CacheClass(JNIEnv *env) {
    if(gClazz == nullptr) {
        auto clazz = env->FindClass("com/example/jni/SystemInfo");
        gClazz = static_cast<jclass>(env->NewGlobalRef(clazz));
    }
}
