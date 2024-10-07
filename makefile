# Compiler
CC = gcc

# Compiler flags
CFLAGS = -lpigpio -lrt -lpthread

# Source files
SRC = traffic_light.c

# Output executable
OUTPUT = traffic_light

# Default target
all: $(OUTPUT)

# Build target
$(OUTPUT): $(SRC)
	$(CC) -o $(OUTPUT) $(SRC) $(CFLAGS)

# Clean target
clean:
	rm -f $(OUTPUT)

# Phony targets
.PHONY: all clean
