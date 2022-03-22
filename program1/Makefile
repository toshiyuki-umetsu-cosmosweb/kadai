CC = clang
SRCS = main.c
CFLAGS = -g -Wall
LDFLAGS = -g
OBJS = $(SRCS:.c=.o)
TARGET = program1.exe

.PHONY : all clean

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) *.o
