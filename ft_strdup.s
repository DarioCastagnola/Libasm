section .text
    global ft_strdup          
    extern malloc             
    extern ft_strlen          

ft_strdup:
    xor al, al                ; clear rax low byte (just to be safe, sets rax=0)
    mov r13, rdi              ; save the input pointer (const char *s) in r13

    call ft_strlen            ; get the length of the string in rdi
    inc rax                   ; add 1 for the null terminator
    mov rdi, rax              ; set rdi = length + 1, argument for malloc
    mov r14, rax              ; save the length in r14 for later copy

    call malloc wrt ..plt     ; allocate memory for the duplicated string
    test rax, rax             ; check if malloc returned NULL
    je return                 ; if malloc failed, jump to return (rax = 0)

    mov rsi, r13              ; source pointer (original string)
    mov rdi, rax              ; destination pointer (malloced memory)
    mov rcx, r14              ; number of bytes to copy (length + null terminator)
    cld                       ; clear the direction flag (copy forwards)
    rep movsb                 ; copy rcx bytes from [rsi] to [rdi]

    ret                       ; return the pointer to the duplicated string in rax

return:
    ret                       ; malloc failed: return 0 (rax already zeroed)
