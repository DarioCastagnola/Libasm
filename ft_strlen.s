section .text
    global ft_strlen

ft_strlen:
    test rdi, rdi                                       ; set flags based on rdi
    je .null_ptr                                        ; if rdi == 0, handle as error
                                                        ;  size_t strlen(const char *s);
    xor rax, rax                                        ; initialize the return value to 0
.loop:
    cmp byte [rdi + rax], 0                             ; checks if current byte is equal to 0
    je .done                                            ; if current byte = 0 exits the loop
    inc rax                                             ; increments counter
    jmp .loop                                           ; loops until byte is equal to 0

.null_ptr:
    xor rax, rax                                        ; return 0 if NULL

.done:
    ret
