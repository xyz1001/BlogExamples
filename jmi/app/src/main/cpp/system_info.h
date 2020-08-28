//
// Created by xyz1001 on 20-8-27.
//

#ifndef JNI_SYSTEM_INFO_H
#define JNI_SYSTEM_INFO_H

#include <string>

#include "jmi.h"

class SystemInfo: public jmi::JObject<SystemInfo> {
public:
    using jmi::JObject<SystemInfo>::JObject;

    static const char *name() {
        return "com/example/jmi/SystemInfo";
    }

public:
    std::string GetOsVersion() const;
    int GetApiLevel() const;
};


#endif //JNI_SYSTEM_INFO_H
