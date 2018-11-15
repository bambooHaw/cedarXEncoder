CC := arm-buildroot-linux-gnueabihf-gcc
INSTALL_DIR := $(shell pwd)/install
INSTALL_DIR_LIBS := $(INSTALL_DIR)/libs
INSTALL_DIR_APPS := $(INSTALL_DIR)/apps
export CC
export INSTALL_DIR_LIBS
export INSTALL_DIR_APPS

SUBDIRS := base common vencoder
SUBDIRS += demo

all:
	-mkdir $(INSTALL_DIR_LIBS)	$(INSTALL_DIR_APPS) -p
	cp $(shell pwd)/libs/*.so $(INSTALL_DIR_LIBS)/ -rf
	@for i in $(SUBDIRS); do $(MAKE) -C $$i all; done

clean:
	rm $(INSTALL_DIR) -rf
	@for i in $(SUBDIRS); do $(MAKE) -C $$i clean ; done

.PHONY: all clean
