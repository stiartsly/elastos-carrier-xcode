include ../Makefile.inc

PACKAGE = libconfuse-3.0.tar.gz
PACKAGE_URL = https://github.com/martinh/libconfuse/archive/v3.0.tar.gz

SRC_DIR = $(DEPS_DIR)/libconfuse-3.0

CONFIG_OPTIONS = --prefix=$(DIST_DIR) \
	--enable-shared=no \
	--disable-shared \
	--enable-static=yes \
	--disable-nls \
	--disable-rpath \
	--without-libiconv \
	--without-libintl \
	--includedir=$(DIST_INC) \
	--libdir=$(DIST_LIB)

CONFIG_STATUS = $(DIST_DIR)/confuse.config.status
COMPILE_STATUS = $(DIST_DIR)/confuse.compile.status
INSTALL_STATUS = $(DIST_DIR)/confuse.install.status

all: install

$(CONFIG_STATUS): $(SRC_DIR)
	mkdir -p $(DIST_DIR) $(DIST_INC) $(DIST_LIB)
	cd $(SRC_DIR) && ./autogen.sh
	cd $(SRC_DIR) && CFLAGS="-g3 -fPIC" ./configure $(CONFIG_OPTIONS)
	@touch $@

$(COMPILE_STATUS): $(CONFIG_STATUS)
	cd $(SRC_DIR) && make
	@touch $@
	@touch $(CONFIG_STATUS)

$(INSTALL_STATUS): $(COMPILE_STATUS)
	cd $(SRC_DIR) && make install
	@touch $@
	@touch $(COMPILE_STATUS)

install: $(INSTALL_STATUS)
	@touch $(INSTALL_STATUS)

clean:
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
	then curl -L $(PACKAGE_URL) -o $(LOCAL_REPO)/$(PACKAGE) ; \
	fi
	tar xzf $(LOCAL_REPO)/$(PACKAGE) -C $(dir $(SRC_DIR))
