section .text
global ft_write
extern __errno_location

                                        ; ssize_t ft_write(int fd, const void *buf, size_t count)
                                        ; Arguments:
                                        ;   rdi = fd
                                        ;   rsi = buf
                                        ;   rdx = count
ft_write:
    mov rax, 1                          ; syscall: write
    syscall                             ; call kernel
                                        ;check for error
    cmp rax, 0
    jge .done                           ; if rax >= 0, success → return

    ; rax < 0 → syscall error
    neg rax                             ; errno = -rax
    mov rdi, rax                        ; save errno in rdi (argument for ___error)
    call __errno_location wrt ..plt     ; returns pointer to errno in rax
    mov [rax], rdi                      ; store errno
    mov rax, -1                         ; return -1 for the caller
.done:
    ret

