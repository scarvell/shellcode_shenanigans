# Shellcode Shenanigans

This is just a little repository to store shellcode that I've written.


To run/debug the asm:

```
$ nasm -f elf64 shellcode.asm -o shellcode.o
$ ld shellcode.o -o shellcode_bin
$ ./shellcode_bin
```

To compile the example C program with the shellcode:

```
 $ gcc -fno-stack-protector -z execstack shellcode.c -o shellcode
 $ ./shellcode
 ```
