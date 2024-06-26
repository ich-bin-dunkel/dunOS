# Makefile for dunOS

# Compiler and flags
CC = gcc
NASM = nasm
LD = ld
CFLAGS = -ffreestanding -nostdlib -lgcc
NASMFLAGS = -f elf
LDFLAGS = -T linker.ld

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Ensure OBJDIR and BINDIR exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Targets
all: $(BINDIR)/os-image.bin

$(BINDIR)/os-image.bin: $(OBJDIR)/boot.o $(OBJ) | $(BINDIR)
	$(LD) $(LDFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/boot.o: boot.asm | $(OBJDIR)
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)/os-image.bin
