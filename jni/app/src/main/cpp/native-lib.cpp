#include <jni.h>
#include <android/log.h>

#include <string>
#include <thread>

#include "system_info.h"

extern "C" JNIEXPORT void JNICALL
Java_com_example_jni_MainActivity_testJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::thread([]{
        SystemInfo info;
        std::string os_version = info.GetOsVersion();
        int api_level = info.GetApiLevel();
        __android_log_print(ANDROID_LOG_INFO, "TestJNI", "os version: %s, api level: %d", os_version.c_str(), api_level);
    }).join();
}
