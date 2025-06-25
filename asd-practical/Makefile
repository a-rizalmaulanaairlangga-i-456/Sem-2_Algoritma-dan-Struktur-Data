CC = gcc
CFLAGS = -Iinclude -Wall

SRC_DIR = src
SORT_DIR = $(SRC_DIR)/sort

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SORT_DIR)/*.c) main.c 

TARGET = main

all = $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -f $(TARGET)