CFLAGS = -pthread -Wall -O3
CPPFLAGS = -I../vencoder/include \
		   -I../common/include \
		   -I../base/include \
		   -I../util/include

LDFLAGS =
LOADLIBES = -L${INSTALL_DIR_LIB}
LDLIBS = -lcedar_vencoder -lcedar_common -lcedar_base -ldl

SRCS = encoderDemo.c
OBJS = $(SRCS:.c=.o)
BINS = $(SRCS:.c=)

.PHONY: all clean

all: clean $(OBJS) $(BINS)

$(BINS): $(OBJS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@
	cp $(BINS) $(INSTALL_DIR_APP) -v
clean:
	$(RM) $(BINS) $(OBJS)
