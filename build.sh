clear 

nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel.c -o kc.o -ffreestanding
gcc -m32 -c include/system.c -o obj/system.o -ffreestanding
gcc -m32 -c include/string.c -o obj/string.o -ffreestanding
gcc -m32 -c include/screen.c -o obj/screen.o -ffreestanding
gcc -m32 -c include/kb.c -o obj/kb.o -ffreestanding

echo " "
echo "gOS [Version 0.0.0]"
echo "Copyright (c) 2018 Gareth Egglestone."
echo "	- Not to be distributed."
echo " "

ld -m elf_i386 -T link.ld -o gOS/boot/kernel.bin kasm.o kc.o obj/system.o obj/string.o obj/screen.o obj/kb.o
qemu-system-i386 -kernel gOS/boot/kernel.bin
grub-mkrescue -o gOS.iso gOS/
