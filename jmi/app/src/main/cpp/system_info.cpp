//
// Created by xyz1001 on 20-8-27.
//

#include "system_info.h"

#include <cassert>
#include <memory>

#define TAG(JavaFunc)             \
    struct JavaFunc : jmi::MethodTag {  \
        static const char *name() { \
            return #JavaFunc;           \
        }                           \
    }

std::string SystemInfo::GetOsVersion() const {
    TAG(getOsVersion);
    auto jver =  call<jstring, getOsVersion>();
    return "";
}

int SystemInfo::GetApiLevel() const {
    TAG(getApiLevel);
    auto jlevel = call<jint, getApiLevel>();
    return static_cast<int>(jlevel);
}
