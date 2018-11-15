CFLAGS = -pthread -Wall -O3
CPPFLAGS = -I../vencoder/include -I../includes

LDFLAGS =
LOADLIBES = -L$(INSTALL_DIR_LIBS)
LDLIBS = -lcedar_vencoder -lcedar_base -lcedar_common -ldl

SRCS = VideoTest.c
OBJS = $(SRCS:.c=.o)
BINS = VideoTest

.PHONY: all clean

all: clean $(OBJS) $(BINS)

$(BINS): $(OBJS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@
	cp $(BINS) $(INSTALL_DIR_APPS)

clean:
	$(RM) $(BINS) $(OBJS)
