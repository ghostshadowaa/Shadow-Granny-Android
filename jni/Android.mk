LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := shadow
LOCAL_SRC_FILES := shadow.cpp
LOCAL_CPPFLAGS := -std=c++17 -Wall -Wextra
LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
