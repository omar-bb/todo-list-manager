# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -Iinclude 

# Target executable
TARGET = todo

# Source and object files
SRC = src/main.c src/todo.c src/file_handler.c src/utils.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile .c files into .o files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Makefile for the To-Do List Manager CLI"
	@echo "Usage:"
	@echo "  make          - Build the project"
	@echo "  make run      - Run the project"
	@echo "  make clean    - Clean up build files"
	@echo "  make help     - Display this help message"

.PHONY: all clean run help
