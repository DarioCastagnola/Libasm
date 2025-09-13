section .text
    global ft_strdup
    extern malloc
    extern ft_strlen
    

ft_strdup:
                                                        ;  char *strdup(const char *s);
    xor rax, rax                                        ; initialize the return value to 0
    mov rsi, rdi                                        ; store rdi into rsi

    call ft_strlen                                      ; strlen of rdi and store it in rax
    inc rax                                             ; so now strlen +1 allows for null terminator
    mov rdi, rax                                        ; store the return of strlen into rdi
    call malloc wrt ..plt                               ; malloc(ft_strlen(*s))       
    xor rcx, rcx                                        ; initialize counter to 0

.loop:
    cmp rdi, rcx                                        ; checks if counter is same as length +1
    je .done                                            ; if current byte = 0 exits the loop
    mov bl, [rsi + rcx]                                 ; copies the byte and store it in bl
    mov [rax + rcx], bl                                 ; moves the byte into the rax
    inc rcx                                             ; increments counter
    jmp .loop                                           ; loops until byte is equal to 0

.done:
    ret