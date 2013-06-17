FILES := $(wildcard src/*.c)
TESTSRC := $(wildcard test/src/*.c)

INCLUDE := include
TESTINCLUDE := test/include

all: debug clean make_iso

test-gcc: $(TESTSRC)

	gcc -I $(TESTINCLUDE) -g -std=c89 $(TESTSRC)

debug: $(FILES)
	
	nasm -felf boot.asm -o boot.o
	i586-elf-gcc -I $(INCLUDE) -c -O2 -ffreestanding -std=c89 $(FILES) ev7.c
	i586-elf-gcc -T linker.ld -o os.bin -ffreestanding -O2 -nostdlib *.o -lgcc

make_iso:

	mv *.bin isodir/boot/
	grub-mkrescue -o os.iso isodir

clean:
	
	rm -f *.o
