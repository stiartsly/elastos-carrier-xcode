include ../Makefile.inc

PACKAGE      = c-toxcore-0.1.10.tar.gz
PACKAGE_URL  = https://github.com/TokTok/c-toxcore/releases/download/v0.1.10/$(PACKAGE_NAME)
SRC_DIR      = $(DEPS_DIR)/c-toxcore-0.1.10

CONFIG_OPTIONS = --prefix=$(DIST_DIR) \
        --with-dependency-search=$(DIST_DIR) \
        --enable-static \
        --disable-shared \
        --disable-ntox \
        --disable-daemon \
        --disable-tests \
        --disable-testing \
        --disable-av

CONFIG_STATUS = $(DIST_DIR)/toxcore.config.status
COMPILE_STATUS = $(DIST_DIR)/toxcore.compile.status
INSTALL_STATUS = $(DIST_DIR)/toxcore.install.status

all: install

$(CONFIG_STATUS): $(SRC_DIR)
	mkdir -p $(DIST_DIR) $(DIST_INC) $(DIST_LIB)
	if [ ! -L $(DIST_DIR)/lib ]; then \
            ln -s $(DIST_LIB) $(DIST_DIR)/lib; \
        fi
	if [ ! -L $(DIST_DIR)/include ]; then \
            ln -s $(DIST_INC) $(DIST_DIR)/include; \
        fi
	$(BUILD_DIR)/patch/toxcore.sh $(SRC_DIR)
	cd $(SRC_DIR) && ./autogen.sh
	cd $(SRC_DIR) && CFLAGS="-g3 -fPIC -DELASTOS_BUILD" ./configure $(CONFIG_OPTIONS)
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
