CC = gcc
CFLAGS = -Iinclude -Wall -g
OBJ = obj/huffman.o obj/compress.o obj/decompress.o obj/main.o
TARGET = huffman

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) -o $@ $^

obj/%.o: src/%.c | obj
    $(CC) $(CFLAGS) -c $< -o $@

obj:
    mkdir -p obj

clean:
    rm -rf obj $(TARGET) compressed.bin output.txt codigos.txt

.PHONY: all clean
