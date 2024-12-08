CC = gcc
CFLAGS = -Wall -g
TARGET = signal

all: $(TARGET)

$(TARGET): signal.c
  $(CC) $(CFLAGS) -o $(TARGET) signal.c

clean:
  rm -f $(TARGET)
