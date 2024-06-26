# Makefile for OS project

# Compiler and flags
CC = gcc
NASM = nasm
LD = ld
CFLAGS = -ffreestanding -nostdlib -lgcc
NASMFLAGS = -f bin
LDFLAGS = -T linker.ld

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Targets
all: $(BINDIR)/os-image.bin

$(BINDIR)/os-image.bin: $(OBJDIR)/boot.o $(OBJ)
    $(LD) $(LDFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/boot.o: boot.asm
    $(NASM) $(NASMFLAGS) -o $@ $<

clean:
    rm -rf $(OBJDIR)/*.o $(BINDIR)/os-image.bin
