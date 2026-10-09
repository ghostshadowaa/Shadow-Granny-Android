#include <jni.h>
#include <android/log.h>
#include <atomic>

#define LOG_TAG "ShadowGranny"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Protótipo: os estados abaixo ainda não alteram a memória ou a lógica do jogo.
namespace {
    std::atomic<bool> g_freeze_granny{false};
    std::atomic<bool> g_god_mode{false};
    std::atomic<bool> g_speed_enabled{false};
    std::atomic<float> g_speed_multiplier{1.5f};
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_shadow_granny_NativeBridge_nativeGetVersion(JNIEnv* env, jclass) {
    return env->NewStringUTF("Shadow Granny Native 0.1 - ARM64 scaffold");
}

extern "C" JNIEXPORT void JNICALL
Java_com_shadow_granny_NativeBridge_nativeSetFreeze(JNIEnv*, jclass, jboolean enabled) {
    g_freeze_granny.store(enabled == JNI_TRUE);
    LOGI("Freeze Granny = %s (estado de exemplo)", enabled ? "ON" : "OFF");
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_shadow_granny_NativeBridge_nativeGetFreeze(JNIEnv*, jclass) {
    return g_freeze_granny.load() ? JNI_TRUE : JNI_FALSE;
}

extern "C" JNIEXPORT void JNICALL
Java_com_shadow_granny_NativeBridge_nativeSetGodMode(JNIEnv*, jclass, jboolean enabled) {
    g_god_mode.store(enabled == JNI_TRUE);
    LOGI("God Mode = %s (estado de exemplo)", enabled ? "ON" : "OFF");
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_shadow_granny_NativeBridge_nativeGetGodMode(JNIEnv*, jclass) {
    return g_god_mode.load() ? JNI_TRUE : JNI_FALSE;
}

extern "C" JNIEXPORT void JNICALL
Java_com_shadow_granny_NativeBridge_nativeSetSpeedEnabled(JNIEnv*, jclass, jboolean enabled) {
    g_speed_enabled.store(enabled == JNI_TRUE);
    LOGI("Speed = %s (estado de exemplo)", enabled ? "ON" : "OFF");
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_shadow_granny_NativeBridge_nativeGetSpeedEnabled(JNIEnv*, jclass) {
    return g_speed_enabled.load() ? JNI_TRUE : JNI_FALSE;
}

extern "C" JNIEXPORT void JNICALL
Java_com_shadow_granny_NativeBridge_nativeSetSpeedMultiplier(JNIEnv*, jclass, jfloat value) {
    if (value >= 0.5f && value <= 3.0f) {
        g_speed_multiplier.store(value);
        LOGI("Multiplicador = %.2f (estado de exemplo)", value);
    }
}

extern "C" JNIEXPORT jfloat JNICALL
Java_com_shadow_granny_NativeBridge_nativeGetSpeedMultiplier(JNIEnv*, jclass) {
    return g_speed_multiplier.load();
}
