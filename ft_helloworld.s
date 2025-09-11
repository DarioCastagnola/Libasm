section .data
    msg db "Hello, world!", 10    ; string with newline
    len equ $ - msg               ; length of the string

section .text
    global _start                 ; entry point

_start:
    ; write(1, msg, len)
    mov rax, 1        ; syscall: write
    mov rdi, 1        ; fd: stdout
    mov rsi, msg      ; pointer to string
    mov rdx, len      ; length
    syscall

    ; exit(0)
    mov rax, 60       ; syscall: exit
    xor rdi, rdi      ; status 0
    syscall