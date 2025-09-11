section .text
    global ft_strcpy

ft_strcpy:
                                                        ;  char *strcpy(char *dest, const char *src);
    xor rax, rax                                        ; initialize the return value to 0