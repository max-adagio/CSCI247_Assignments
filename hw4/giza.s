    
        
        .global main
    .text
main:
    # ./giza (int)
    # takes argv[1], converts from ascii to int, then pushes onto stack
    mov     8(%rsi), %rdi     # pushes argv[1] onto the stack
    push    %r8               # push junk for stack alignment
    call    atoi

    mov     %rax, %r10  # num = (int) argv[1]
    mov     $0, %r8     # i = 0
    mov     $0, %r9     # j = 0
    mov     $0, %r13

outer:
    cmp     %r10, %r8
    jnl     quit        # while (i < num)
    mov     %r8, %r9    # j = i  

inner:
    cmp     %r13, %r9
    jl      newline
    # prints "*"
    mov     $1, %rax
    mov     $1, %rdi
    mov     $star, %rsi
    mov     $1, %rdx
    syscall

    dec     %r9
    jmp     inner
    
newline:
    mov     $1, %rax
    mov     $1, %rdi
    mov     $nl, %rsi
    mov     $1, %rdx
    syscall

    inc     %r8     # i++
    jmp     outer

quit:

    mov     $1, %rax
    mov     $1, %rdi
    mov     $finito, %rsi
    mov     $7, %rdx
    syscall


    mov    $60, %rax
    mov    $0, %rdi
    syscall


        .data
star: .ascii "*"
nl: .ascii "\n"
finito: .ascii "Finito\n"

