CC = clang
SRCS = main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -g
LDFLAGS = $(CFLAGS)
TARGET = $(notdir $(shell pwd)).exe

.PHONY : all clean

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f $(TARGET) *.o
