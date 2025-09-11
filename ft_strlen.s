section .text
    global ft_strlen

ft_strlen:
                                                        ;  size_t strlen(const char *s);
    xor rax, rax                                        ; initialize the return value to 0
.loop:
    cmp byte [rdi + rax], 0                             ; checks if current byte is equal to 0
    je .done                                            ; if current byte = 0 exits the loop
    inc rax                                             ; increments counter
    jmp .loop                                           ; loops until byte is equal to 0

.done:
    ret
