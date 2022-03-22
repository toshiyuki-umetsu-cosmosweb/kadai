CC = clang
SRCS = main.c
CFLAGS = -std=c99 -Wall -g
LDFLAGS = -g
OBJS = $(SRCS:.c=.o)
TARGET = $(notdir $(shell pwd)).exe

.PHONY : all clean


all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) *.o
