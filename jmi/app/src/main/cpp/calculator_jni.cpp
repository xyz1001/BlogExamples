//
// Created by xyz1001 on 20-8-27.
//

#include <cassert>

#include <jni.h>

#include "calculator.h"

extern "C" {
JNIEXPORT void JNICALL
Java_com_example_jmi_Calculator_plus(JNIEnv *env, jobject thiz, jint a) {
    jclass clazz = env->FindClass("com/example/jmi/Calculator");
    assert(clazz);
    jfieldID id = env->GetFieldID(clazz, "mInstance", "J");
    assert(id);
    auto calculator = reinterpret_cast<Calculator*>(env->GetLongField(thiz, id));

    calculator->Plus(int(a));
}

JNIEXPORT void JNICALL
Java_com_example_jmi_Calculator_minus(JNIEnv *env, jobject thiz, jint a) {
    jclass clazz = env->FindClass("com/example/jmi/Calculator");
    assert(clazz);
    jfieldID id = env->GetFieldID(clazz, "mInstance", "J");
    assert(id);
    auto calculator = reinterpret_cast<Calculator*>(env->GetLongField(thiz, id));

    calculator->Minus(int(a));
}

JNIEXPORT void JNICALL
Java_com_example_jmi_Calculator_multi(JNIEnv *env, jobject thiz, jint a) {
    jclass clazz = env->FindClass("com/example/jmi/Calculator");
    assert(clazz);
    jfieldID id = env->GetFieldID(clazz, "mInstance", "J");
    assert(id);
    auto calculator = reinterpret_cast<Calculator*>(env->GetLongField(thiz, id));

    calculator->Multi(int(a));
}

JNIEXPORT void JNICALL
Java_com_example_jmi_Calculator_divide(JNIEnv *env, jobject thiz, jint a) {
    jclass clazz = env->FindClass("com/example/jmi/Calculator");
    assert(clazz);
    jfieldID id = env->GetFieldID(clazz, "mInstance", "J");
    assert(id);
    auto calculator = reinterpret_cast<Calculator*>(env->GetLongField(thiz, id));

    calculator->Divide(int(a));
}

JNIEXPORT jint JNICALL
Java_com_example_jmi_Calculator_getResult(JNIEnv *env, jobject thiz) {
    jclass clazz = env->FindClass("com/example/jmi/Calculator");
    assert(clazz);
    jfieldID id = env->GetFieldID(clazz, "mInstance", "J");
    assert(id);
    auto calculator = reinterpret_cast<Calculator*>(env->GetLongField(thiz, id));

    return static_cast<jint>(calculator->GetResult());
}

JNIEXPORT jlong JNICALL
Java_com_example_jmi_Calculator_createNativeObject(JNIEnv *env, jobject thiz) {
    auto calculator = new Calculator;
    return reinterpret_cast<jlong>(calculator);
}

JNIEXPORT void JNICALL
Java_com_example_jmi_Calculator_releaseNativeObject(JNIEnv *env, jobject thiz) {
    jclass clazz = env->FindClass("com/example/jmi/Calculator");
    assert(clazz);
    jfieldID id = env->GetFieldID(clazz, "mInstance", "J");
    assert(id);

    auto calculator = reinterpret_cast<Calculator*>(env->GetLongField(thiz, id));
    delete calculator;
}

}
