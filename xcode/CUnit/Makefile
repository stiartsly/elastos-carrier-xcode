include ../Makefile.inc

PACKAGE = CUnit-2.1-3.tar.bz2
PACKAGE_URL = http://jaist.dl.sourceforge.net/project/cunit/CUnit/2.1-3/$(PACKAGE)

SRC_DIR = $(DEPS_DIR)/CUnit-2.1-3

CONFIG_OPTIONS = --prefix=$(DIST_DIR) --includedir=$(DIST_INC) --libdir=$(DIST_LIB)

CONFIG_STATUS = $(DIST_DIR)/CUnit.config.status
COMPILE_STATUS = $(DIST_DIR)/CUnit.compile.status
INSTALL_STATUS = $(DIST_DIR)/CUnit.install.status

all: install

$(CONFIG_STATUS): $(SRC_DIR)
	mkdir -p $(DIST_DIR) $(DIST_INC) $(DIST_LIB)
	cd $(SRC_DIR) && aclocal && autoconf && autoreconf -if
	cd $(SRC_DIR) && CFLAGS="-g3 -Wformat=0" ./configure $(CONFIG_OPTIONS)
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
	then curl $(PACKAGE_URL) -o $(LOCAL_REPO)/$(PACKAGE) ; \
	fi
	tar xjf $(LOCAL_REPO)/$(PACKAGE) -C $(dir $(SRC_DIR))
