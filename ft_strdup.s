section .text
    global ft_strdup
    extern malloc
    extern ft_strlen

ft_strdup:
    mov r8, rdi              ; salva puntatore originale in r8

    call ft_strlen           ; rax = strlen(s)
    mov rcx, rax              ; rcx = len
    inc rcx                   ; rcx = len + 1 (incluso terminatore)

    mov rdi, rcx               ; malloc(len+1)
    call malloc wrt ..plt
    test rax, rax
    je .done

    mov rsi, r8                ; rsi = sorgente
    mov rdi, rax                ; rdi = destinazione
    mov rdx, rcx                ; rdx = len+1 da copiare

.copy_loop:
    mov bl, [rsi]       ; carica il byte corrente della sorgente in bl
    mov [rdi], bl       ; scrive quel byte nella destinazione
    inc rsi             ; avanza di 1 nella sorgente
    inc rdi             ; avanza di 1 nella destinazione
    dec rdx             ; abbiamo copiato 1 byte, quindi ne restano uno in meno
    jnz .copy_loop      ; se rdx != 0, salta indietro e copia il prossimo

    sub rdi, rcx                ; riportiamo rdi all'inizio
    mov rax, rdi                ; rax = puntatore allocato

.done:
    ret
