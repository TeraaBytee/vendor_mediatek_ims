LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    ifc_utils.c

LOCAL_C_INCLUDES += \
    vendor/mediatek/ims/radio_stack/platformlib/include

LOCAL_SHARED_LIBRARIES := \
    libmtkrillog \
    libmtkproperty

LOCAL_PROTOC_OPTIMIZE_TYPE := nanopb-c-enable_malloc

LOCAL_MODULE:= libmtknetutils
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk

include $(BUILD_SHARED_LIBRARY)
