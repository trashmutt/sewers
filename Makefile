CC = gcc
TARGET = bin/sewers
SRC = $(wildcard src/*.c)

RAYLIB_PREFIX := $(shell brew --prefix raylib)

CFLAGS = -I$(RAYLIB_PREFIX)/include
LDFLAGS = -L$(RAYLIB_PREFIX)/lib -Wl,-rpath,$(RAYLIB_PREFIX)/lib -lraylib

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
