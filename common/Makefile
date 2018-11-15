CPPFLAGS = -Iinclude -I../util
DEP_CFLAGS = -MMD -MP -MF $(@:%.o=%.d) -MT $(@:%.o=%.d)
CFLAGS = -pthread -Wall -O3 -fpic -fvisibility=hidden -fomit-frame-pointer
LDFLAGS = -shared -Wl,-soname,$(BINS)
LOADLIBES = -L../base
LDLIBS = -lcedar_base

BINS = libcedar_common.so
SRCS = ve.c ve_alloc.c ion_alloc.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

.PHONY: all clean

all: $(OBJS) $(BINS)

$(BINS): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@
	cp $(BINS) $(INSTALL_DIR_LIBS)

%.o: %.c
	$(CC) $(DEP_CFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(BINS) $(OBJS) $(DEPS)

include $(wildcard $(DEPS))
