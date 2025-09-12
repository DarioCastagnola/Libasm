section .text
    global ft_strcpy

ft_strcpy:
                                                        ;  char *strcpy(char *dest, const char *src);
    xor rax, rax                                        ; initialize the return value to 0
    xor rcx, rcx                                        ; initialize counter to 0

.loop:
    cmp byte [rsi + rcx], 0                             ; checks if current byte is equal to 0
    je .done                                            ; if current byte = 0 exits the loop
    mov al, [rsi + rcx]                                 ; copies the byte and store it in al
    mov [rdi + rcx], al                                 ; moves the byte from al to rdi
    inc rcx                                             ; increments counter
    jmp .loop                                           ; loops until byte is equal to 0

.done:
    mov rax, rdi                                        ; sets the return value to rdi
    ret