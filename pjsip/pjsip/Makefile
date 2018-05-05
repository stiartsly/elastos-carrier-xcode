include ../Makefile.inc

PACKAGE = pjproject-2.5.5.tar.bz2
PACKAGE_URL = http://www.pjsip.org/release/2.5.5/$(PACKAGE)
VERSION = $(shell uname -r)

SRC_DIR = $(DEPS_DIR)/pjproject-2.5.5

CONFIG_OPTIONS = --prefix=$(DIST_DIR) \
	--enable-ssl \
	--disable-shared \
	--disable-resample \
	--disable-sound \
	--disable-oss \
	--disable-video \
	--disable-ext-sound  \
	--disable-small-filter \
	--disable-large-filter \
	--disable-speex-aec \
	--disable-g711-codec \
	--disable-l16-codec \
	--disable-gsm-codec \
	--disable-g722-codec \
	--disable-g7221-codec \
	--disable-speex-codec \
	--disable-ilbc-codec \
	--disable-libsamplerate \
	--disable-resample-dll \
	--disable-sdl \
	--disable-ffmpeg \
	--disable-v4l2 \
	--disable-openh264 \
	--disable-webrtc \
	--disable-ipp \
	--disable-opencore-amr \
	--disable-silk \
	--disable-opus \
	--disable-libyuv \
	--with-ssl=$(DIST_DIR) \
	--includedir=$(DIST_INC) \
	--libdir=$(DIST_LIB)

CONFIG_STATUS = $(DIST_DIR)/pjsip.config.status
COMPILE_STATUS = $(DIST_DIR)/pjsip.compile.status
INSTALL_STATUS = $(DIST_DIR)/pjsip.install.status

all: install

$(CONFIG_STATUS): $(SRC_DIR)
	mkdir -p $(DIST_DIR) $(DIST_INC) $(DIST_LIB)
	cd $(SRC_DIR) && CFLAGS="-g3 -fPIC" ./configure $(CONFIG_OPTIONS)
	sed -ie "s/^#[[:space:]]*define[[:space:]]*PJ_STUN_SOCK_PKT_LEN[[:space:]]*2000/#   define PJ_STUN_SOCK_PKT_LEN			    2176/" "$(SRC_DIR)/pjnath/include/pjnath/config.h"
	@touch $@

$(COMPILE_STATUS): $(CONFIG_STATUS)
	cd $(SRC_DIR) && make
	@touch $@
	@touch $(CONFIG_STATUS)

$(INSTALL_STATUS): $(COMPILE_STATUS)
	cd $(SRC_DIR) && make install
	cp -f $(DIST_LIB)/libpj-x86_64-apple-darwin$(VERSION).a $(DIST_LIB)/libpj.a
	cp -f $(DIST_LIB)/libpjlib-util-x86_64-apple-darwin$(VERSION).a $(DIST_LIB)/libpjlib-util.a
	cp -f $(DIST_LIB)/libpjnath-x86_64-apple-darwin$(VERSION).a $(DIST_LIB)/libpjnath.a
	cp -f $(DIST_LIB)/libpjmedia-x86_64-apple-darwin$(VERSION).a $(DIST_LIB)/libpjmedia.a
	@touch $@
	@touch $(COMPILE_STATUS)

install: $(INSTALL_STATUS)
	@touch $(INSTALL_STATUS)

clean:
	rm -f $(DIST_LIB)/libpj.a
	rm -f $(DIST_LIB)/libpjlib-util.a
	rm -f $(DIST_LIB)/libpjnath.a
	rm -f $(DIST_LIB)/libpjmedia.a
	if [ -d $(SRC_DIR) ]; then \
            cd $(SRC_DIR) && make clean; \
        fi
	rm -f $(INSTALL_STATUS)
	rm -f $(COMPILE_STATUS)
	rm -f $(CONFIG_STATUS)

$(SRC_DIR):
	mkdir -p $(DEPS_DIR)
	mkdir -p $(LOCAL_REPO)
	if [ ! -s $(LOCAL_REPO)/$(PACKAGE) ] ; \
	then curl $(PACKAGE_URL) -o $(LOCAL_REPO)/$(PACKAGE) ; \
	fi
	tar xjf $(LOCAL_REPO)/$(PACKAGE) -C $(dir $(SRC_DIR))
