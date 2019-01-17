CC = arm-buildroot-linux-gnueabihf-gcc
INSTALL_DIR = $(shell pwd)/install
INSTALL_DIR_LIB = ${INSTALL_DIR}/lib
INSTALL_DIR_APP = ${INSTALL_DIR}/app

export CC
export INSTALL_DIR_LIB
export INSTALL_DIR_APP

SUBDIRS = base common vencoder demo


all:
	-mkdir ${INSTALL_DIR_LIB} ${INSTALL_DIR_APP} -p
	cp ${shell pwd}/libs/* ${INSTALL_DIR_LIB} -v
	@for i in $(SUBDIRS); do $(MAKE) -C $$i all ; done

clean:
	rm ${INSTALL_DIR} -rf
	@for i in $(SUBDIRS); do $(MAKE) -C $$i clean ; done

.PHONY: all clean







