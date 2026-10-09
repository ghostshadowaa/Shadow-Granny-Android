#include <jni.h>
#include <android/log.h>
#include <atomic>
#include "il2cpp_backend.h"
#define LOG_TAG "ShadowGranny"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
namespace {
std::atomic<bool> freezeState{false}, godState{false}, speedState{false};
std::atomic<float> speedMultiplier{1.5f};
}
extern "C" JNIEXPORT jstring JNICALL Java_com_shadow_granny_NativeBridge_nativeGetVersion(JNIEnv* env,jclass) {
    return env->NewStringUTF("Shadow Granny 0.2 - IL2CPP backend experimental");
}
extern "C" JNIEXPORT void JNICALL Java_com_shadow_granny_NativeBridge_nativeSetFreeze(JNIEnv*,jclass,jboolean enabled) {
    freezeState.store(enabled==JNI_TRUE);
    bool ok=shadow_il2cpp_set_freeze(enabled==JNI_TRUE);
    LOGI("Freeze=%d runtime=%d status=%s",enabled==JNI_TRUE,ok,shadow_il2cpp_status());
}
extern "C" JNIEXPORT jboolean JNICALL Java_com_shadow_granny_NativeBridge_nativeGetFreeze(JNIEnv*,jclass) {
    return freezeState.load()?JNI_TRUE:JNI_FALSE;
}
extern "C" JNIEXPORT void JNICALL Java_com_shadow_granny_NativeBridge_nativeSetGodMode(JNIEnv*,jclass,jboolean enabled) {
    godState.store(enabled==JNI_TRUE);
    bool ok=shadow_il2cpp_set_god_mode(enabled==JNI_TRUE);
    LOGI("GodMode=%d runtime=%d status=%s",enabled==JNI_TRUE,ok,shadow_il2cpp_status());
}
extern "C" JNIEXPORT jboolean JNICALL Java_com_shadow_granny_NativeBridge_nativeGetGodMode(JNIEnv*,jclass) {
    return godState.load()?JNI_TRUE:JNI_FALSE;
}
extern "C" JNIEXPORT void JNICALL Java_com_shadow_granny_NativeBridge_nativeSetSpeedEnabled(JNIEnv*,jclass,jboolean enabled) {
    speedState.store(enabled==JNI_TRUE);
    bool ok=shadow_il2cpp_set_speed(enabled==JNI_TRUE,speedMultiplier.load());
    LOGI("Speed=%d runtime=%d status=%s",enabled==JNI_TRUE,ok,shadow_il2cpp_status());
}
extern "C" JNIEXPORT jboolean JNICALL Java_com_shadow_granny_NativeBridge_nativeGetSpeedEnabled(JNIEnv*,jclass) {
    return speedState.load()?JNI_TRUE:JNI_FALSE;
}
extern "C" JNIEXPORT void JNICALL Java_com_shadow_granny_NativeBridge_nativeSetSpeedMultiplier(JNIEnv*,jclass,jfloat value) {
    if(value>=0.5f&&value<=3.0f) {
        speedMultiplier.store(value);
        if(speedState.load()) {
            bool ok=shadow_il2cpp_set_speed(true,value);
            LOGI("Multiplier=%.2f runtime=%d status=%s",value,ok,shadow_il2cpp_status());
        }
    }
}
extern "C" JNIEXPORT jfloat JNICALL Java_com_shadow_granny_NativeBridge_nativeGetSpeedMultiplier(JNIEnv*,jclass) {
    return speedMultiplier.load();
}
