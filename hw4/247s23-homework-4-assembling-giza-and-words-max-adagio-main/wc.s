        .global main

        .text
main:                                   # This is called by C library's startup code
        # TODO: Your code here
        ret

# The print_result function takes one arg in %edi, and prints the
# result as "Result=xxx" on standard output using printf.
print_result:
        push    %rbp
        mov     %rsp, %rbp
        mov     %edi, %esi            # arg2 is the number
        mov     $format, %rdi         # arg1 is the format string
        call    printf
        pop     %rbp

        ret

# The isspace function takes one arg in %edi, and returns 1 in %eax if
# if the arg is a whitespace, or 0 in %eax if the arg is not a whitespace
isspace:
        # arg1 in %edi, compare it to space (32), newline (10),
        # carriage return (13) and tab (9)
        # TODO: Your code here
        ret

# The skipws function reads from standard input, until it sees a non
# space character or end of file. It returns -1 on EOF or 0 otherwise.
skipws:

skipws_top:
        # read a character, the result is in %eax
    	push 	%rbp
    	mov   	%rsp, %rbp
    	call	getchar
        pop     %rbp

        # check if getchar returned EOF
    	cmp    	$-1, %eax
        jne	    skipws_checkspace

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
        je	    skipws_top       # was a space, so we keep looping

        mov 	$0, %eax         # not a space, so we return from the function
    	ret


# The readword function reads from standard input, until it sees a white
# space character or end of file. It returns -1 on EOF or 0 otherwise.
readword:
readword_top:
        # TODO: Your code here
    	ret

format:
        .asciz  "Result=%d\n"
