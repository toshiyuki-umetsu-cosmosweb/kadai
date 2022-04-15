CC = clang
SRCDIRS = src
SRCS = $(foreach srcdir, $(SRCDIRS), $(wildcard $(srcdir)/*.c))
CFLAGS = -g -Wall
LDFLAGS = -g -lm
ARCH = $(shell uname -p)
OUTDIR = $(ARCH)
OBJS = $(foreach src, $(SRCS), $(OUTDIR)/$(src:.c=.o))

TARGET = $(notdir $(shell pwd)).exe

.PHONY : all clean

all : $(TARGET) $(OUTDIR)

$(OUTDIR):
	mkdir -p $@

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	
$(OUTDIR)/%.o : %.c
	@if [ ! -d $(dir $@) ] ; then \
	    mkdir -p $(dir $@); \
	fi
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) 
	rm -rf $(OUTDIR)
