TARGET = :clang
ARCHS = armv7 armv7s arm64

include theos/makefiles/common.mk

TWEAK_NAME = DarkPhotos
DarkPhotos_FILES = DarkPhotos.xm
DarkPhotos_FRAMEWORKS = UIKit
DarkPhotos_PRIVATE_FRAMEWORKS = PhotosUI

include $(THEOS_MAKE_PATH)/tweak.mk
include $(THEOS_MAKE_PATH)/aggregate.mk