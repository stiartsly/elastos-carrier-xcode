BUILD_DIR = $(shell pwd)/../../build

ROOT_DIR = $(BUILD_DIR)/..

OS = $(shell uname -s)
ARCH = $(shell uname -m)

DIST_DIR = $(BUILT_PRODUCTS_DIR)

DIST_LIB = $(DIST_DIR)/usr/local/lib

DIST_INC = $(DIST_DIR)/usr/local/include

DEPS_DIR = $(BUILD_DIR)/_build/Xcode/$(CONFIGURATION)

LOCAL_REPO = $(BUILD_DIR)/.tarballs
