section .text
    global ft_strcmp

ft_strcmp:
                                                        ;  int ft_strcmp(const char *s1, const char *s2);
    xor rcx, rcx
    xor rax, rax

.loop:
    mov al, [rdi + rcx]   ; carica s1[i] in al
    mov bl, [rsi + rcx]   ; carica s2[i] in bl                      
    cmp al, bl                  
    jne .done
    cmp byte [rdi + rcx], 0
    je .equal
    inc rcx
    jmp .loop

.done:
    movzx rax, al
    movzx rbx, bl
    sub rax, rbx
    ret

.equal:
    xor rax, rax
    ret