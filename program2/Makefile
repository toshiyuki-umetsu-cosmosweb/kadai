SRCS = main.c
IR_FILES = $(SRCS:.c=.ll)
ASM_FILES = $(IR_FILES:.ll=.s)
TARGET = program2.exe



all : $(TARGET)

$(TARGET) : $(ASM_FILES)
	clang $(ASM_FILES) -o $@
	

%.s : %.ll
	llc -o $@ $<

%.ll : %.c
	clang -S -emit-llvm -o $@ $<

clean:
	rm -f $(TARGET) *.ll *.s
