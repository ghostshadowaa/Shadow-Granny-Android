LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := shadow
LOCAL_SRC_FILES := shadow.cpp il2cpp_backend.cpp
LOCAL_CPPFLAGS := -std=c++17 -Wall -Wextra
LOCAL_LDLIBS := -llog -ldl
include $(BUILD_SHARED_LIBRARY)
