//
// Created by xyz1001 on 20-8-27.
//

#ifndef JNI_SYSTEM_INFO_H
#define JNI_SYSTEM_INFO_H

#include <string>

#include <jni.h>

class SystemInfo {
public:
    SystemInfo();
    ~SystemInfo();

public:
    std::string GetOsVersion() const;
    int GetApiLevel() const;

    static void CacheClass(JNIEnv *env);

private:
    jobject object_{};
};


#endif //JNI_SYSTEM_INFO_H
