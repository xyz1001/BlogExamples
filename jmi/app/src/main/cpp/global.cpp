//
// Created by xyz1001 on 20-8-27.
//

#include <cassert>

#include <memory>

#include "system_info.h"

#ifdef __cplusplus
extern "C" {
#endif

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    jmi::javaVM(vm, JNI_VERSION_1_6);
    static_cast<jclass>(SystemInfo());
    return JNI_VERSION_1_4;
}

#ifdef __cplusplus
}
#endif


