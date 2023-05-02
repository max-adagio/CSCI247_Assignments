# Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
# To assemble and run:
#
# gcc -no-pie readnum.s -o readnum
# ----------------------------------------------------------------------------------------
        
    .global main
    .text
main:   

# prompt 1
# "Please enter a number : "
    mov $1, %rax        # system call for write
    mov $1, %rdi        # file handle 1 is stdout
    mov $message, %rsi  # address of number to output
    mov $23, %rdx       # number of bytes
    syscall             # invoke operating system to do the write

# Read from stdin the first number, num1
    mov $0, %rax        # system call for read
    mov $0, %rdi        # file handle 0 is stdin
    mov $num1, %rsi
    mov $100, %rdx
    syscall

# converts num1 from a to i, stores in r10
    mov $num1, %rdi
    call atoi
    mov %rax, %r8
    push %r8

# prompt 2
# "Please enter a number : "
    mov $1, %rax        # system call for write
    mov $1, %rdi        # file handle 1 is stdout
    mov $message, %rsi  # address of number to output
    mov $23, %rdx       # number of bytes
    syscall             # invoke operating system to do the write

# Read from stdin
    mov $0, %rax        # system call for read
    mov $0, %rdi        # file handle 0 is stdin
    mov $num2, %rsi
    mov $100, %rdx
    syscall

# converts num2 from a to i, stores in r11
    mov $num2, %rdi
    call atoi
    mov %rax, %r9



##########################################################
# perform the addition
    pop %r8
    add %r8, %r9
    push %r8 # NEW
    
    # call puts

# Write sum
    mov $response, %rdi
    mov %r9, %rsi
    mov $0, %al
    call printfS
    pop %r8 # NEW

# Exits the System
    mov $0, %rax       # system call for exit
    ret

    .data

message: .string "Please enter a number: "
response: .string "The sum is: %d\n"
num1: .zero 100
num2: .zero 100
