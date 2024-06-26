CC = gcc
CFLAGS = -ffreestanding -nostdlib -lgcc

all: os-image.bin

os-image.bin: boot.bin kernel.bin
    cat boot.bin kernel.bin > os-image.bin

boot.bin: boot.asm
    nasm -f bin -o boot.bin boot.asm

kernel.bin: kernel.o tui.o terminal.o fs.o idt.o paging.o syscall.o editor.o pong.o
    ld -o kernel.bin -T linker.ld kernel.o tui.o terminal.o fs.o idt.o paging.o syscall.o editor.o pong.o

kernel.o: kernel.c
    $(CC) $(CFLAGS) -c kernel.c -o kernel.o

tui.o: tui.c tui.h
    $(CC) $(CFLAGS) -c tui.c -o tui.o

terminal.o: terminal.c terminal.h
    $(CC) $(CFLAGS) -c terminal.c -o terminal.o

fs.o: fs.c fs.h
    $(CC) $(CFLAGS) -c fs.c -o fs.o

idt.o: idt.c idt.h
    $(CC) $(CFLAGS) -c idt.c -o idt.o

paging.o: paging.c paging.h
    $(CC) $(CFLAGS) -c paging.c -o paging.o

syscall.o: syscall.c syscall.h
    $(CC) $(CFLAGS) -c syscall.c -o syscall.o

editor.o: editor.c editor.h
    $(CC) $(CFLAGS) -c editor.c -o editor.o

pong.o: pong.c pong.h
    $(CC) $(CFLAGS) -c pong.c -o pong.o

clean:
    rm -f *.bin *.o os-image.bin
