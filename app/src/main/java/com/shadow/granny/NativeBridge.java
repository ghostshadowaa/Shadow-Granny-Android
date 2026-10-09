package com.shadow.granny;

public final class NativeBridge {
    static {
        System.loadLibrary("shadow");
    }

    private NativeBridge() {}

    public static native String nativeGetVersion();
    public static native void nativeSetFreeze(boolean enabled);
    public static native boolean nativeGetFreeze();
    public static native void nativeSetGodMode(boolean enabled);
    public static native boolean nativeGetGodMode();
    public static native void nativeSetSpeedEnabled(boolean enabled);
    public static native boolean nativeGetSpeedEnabled();
    public static native void nativeSetSpeedMultiplier(float value);
    public static native float nativeGetSpeedMultiplier();
}
