        .global main

        .text
main:
        # write(1, message, 13)
        mov     $1, %rax                # system call 1 is write
        mov     $1, %rdi                # file handle 1 is stdout
        mov     $message, %rsi          # address of string to output
        mov     $13, %rdx               # number of bytes
        syscall                         # invoke operating system 

        # exit(0)
        mov     $0, %eax               # return 0
        ret

	   # char* message = "Hello, world\n"
message: 
  .ascii  "Hello, world\n"
