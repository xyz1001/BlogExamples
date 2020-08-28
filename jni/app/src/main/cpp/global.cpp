//
// Created by xyz1001 on 20-8-27.
//

#include "global.h"

#include <cassert>

#include <memory>

#include "system_info.h"

namespace {
JavaVM *jvm = nullptr;
}

JavaVM *GetJVM() {
    return jvm;
}

#ifdef __cplusplus
extern "C" {
#endif

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    jvm = vm;

    // 这里的env是不需要释放的，因为当前线程是JAVA线程，不能从JAVA层脱离
    JNIEnv *env;
    jint ret = jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
    assert(env);
    SystemInfo::CacheClass(env);

    return JNI_VERSION_1_6;
}

void JNI_OnUnload(JavaVM *vm, void *reserved) {
    jvm = nullptr;
}

#ifdef __cplusplus
}
#endif


