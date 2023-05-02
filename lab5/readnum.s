# Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
# To assemble and run:
#
# gcc -no-pie readnum.s -o readnum
# ----------------------------------------------------------------------------------------
        
        .global main
    .text
main:   

# prompt 
    mov $1, %rax        # system call for write
    mov $1, %rdi        # file handle 1 is stdout

    mov $message, %rsi  # address of number to output
    mov $23, %rdx       # number of bytes

    syscall             # invoke operating system to do the write

# Read from stdin
    mov $0, %rax        # system call for read
    mov $0, %rdi        # file handle 0 is stdin
    mov $buffer, %rsi        # number of bytes for 1 int
    mov $100, %rdx
    syscall             # invoke OS to do the read


# write message back in stdout 
    mov $1, %rax        # system call for write
    mov $1, %rdi        # file handle 1 is stdout

    mov $response, %rsi  # address of number to output
    mov $18, %rdx       # number of bytes

    syscall             # invoke operating system to do the write

# Write number to stdout

    mov $1, %rax        # system call for write
    mov $1, %rdi        # file handle 1 is stdout
    mov $buffer, %rsi
    mov $100, %rdx
    syscall             # invoke operating system to do the write


# Exit Program
    mov $60, %rax       # system call for exit
    mov $0, %rdi        # exit code 0
    syscall             # invoke operating system to exit



    .data
buffer: .zero 100
message: .ascii "Please enter a number: "
response: .ascii "You have entered: "
