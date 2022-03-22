CC = clang
SRCS = main.c write_proc.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -g -Wall
LDFLAGS = -g -Wall
TARGET = $(notdir $(shell pwd)).exe

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ 
	
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(TARGET) *.o
