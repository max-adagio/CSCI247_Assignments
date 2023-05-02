.global main
.text
main:                                   # This is called by C library's startup code
        
        mov     $0, %r12        # ecx holds the result variable
main_top:
        push    %rbp
        mov     %rsp, %rbp
        call    skipws

        pop     %rbp
        cmp     $-1, %eax
        je      terminate

        push    %rbp
        mov     %rsp, %rbp
        call    readword
        
        pop     %rbp
        inc     %r12
        cmp     $-1, %eax      # readword returns either 1 or 0 in %eax
        je      terminate

        
        jmp     main_top

        # jmp     skipws
        # cmp     %ebx, %eax
        # je      print_result
        # jmp     main
        ret

        # TODO: Your code here

terminate:
        mov     %r12d, %edi

        push    %rbp
        mov     %rsp, %rbp
        call    print_result
        pop     %rbp
        mov     $0, %eax
        ret

# The print_result function takes one arg in %edi, and prints the
# result as "Result=xxx" on standard output using printf.
print_result:

        mov     %edi, %esi            # arg2 is the number
        mov     $format, %edi         # arg1 is the format string

        push    %rbp
        mov     %rsp, %rbp
        call    printf
        pop     %rbp

        ret

# The isspace function takes one arg in %edi, and returns 1 in %eax if
# if the arg is a whitespace, or 0 in %eax if the arg is not a whitespace
isspace:
        # arg1 in %edi, compare it to space (32), newline (10),
        # carriage return (13) and tab (9)
        # TODO: Your code here

        cmp     $32, %edi
        je      returnOne

        cmp     $10, %edi
        je      returnOne

        cmp     $13, %edi
        je      returnOne

        cmp     $9, %edi
        je      returnOne
        
        mov     $0, %eax
        ret

returnOne:
        mov     $1, %eax
        ret

# The skipws function reads from standard input, until it sees a non
# space character or end of file. It returns -1 on EOF or 0 otherwise.
skipws:

skipws_top:
        # read a character, the result is in %eax
    	push 	%rbp
    	mov   	%rsp, %rbp

    	call	getchar # suppose to return into %eax
        pop     %rbp

        # check if getchar returned EOF
    	cmp    	$-1, %eax
        jne	skipws_checkspace

        # We got an EOF, so return -1 in %eax
        mov	    $-1, %eax
        ret

skipws_checkspace:
        # Check whether the character we read was a space
        push    %rbp
        mov     %rsp, %rbp
        movl	%eax, %edi       # the char read was in %eax
        call	isspace
        pop     %rbp

        cmp 	$1, %eax
        je	skipws_top       # was a space, so we keep looping

        mov 	$0, %eax         # not a space, so we return from the function
    	ret



# The readword function reads from standard input, until it sees a white
# space character or end of file. It returns -1 on EOF or 0 otherwise.
readword:
readword_top:
        # TODO: Your code here
        # read a character, the result is in %eax
    	push 	%rbp
    	mov   	%rsp, %rbp
    	call	getchar
        pop     %rbp

        # check if getchar returned EOF
    	cmp    	$-1, %eax       # 46 is '.' in giza. %eax should contain 46 'h'
        jne	readword_checkchar

        # We got an EOF, so return -1 in %eax
        mov	    $-1, %eax
        ret

readword_checkchar:
        # Check whether the character we read was a space
        push    %rbp
        mov     %rsp, %rbp
        movl	%eax, %edi       # the char read was in %eax
        call	isspace
        pop     %rbp

        cmp 	$1, %eax
        jne	readword_top       # was a space, so we keep looping

        mov 	$0, %eax         # not a space, so we return from the function
    	ret

        

format:
        .asciz  "Result=%d\n"
