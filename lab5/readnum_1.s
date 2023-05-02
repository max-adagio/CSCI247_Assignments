# Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
# To assemble and run:
#
# gcc -no-pie readnum.s -o readnum
# ----------------------------------------------------------------------------------------
        
        .global main
    .text
main:   

# Read from stdin
    mov $0, %rax        # system call for read
    mov $0, %rdi        # file handle 0 is stdin
    mov $4, %rdx        # number of bytes for 1 int
    syscall             # invoke OS to do the read
    mov %rax, %r9
    # mov $60, %rax       # exit system call
    # mov $99, %rdi        # exit code 0

# Write number to stdout
    mov $1, %rax        # system call for write
    mov $1, %rdi        # file handle 1 is stdout

    mov $format, %rsi  # address of number to output
    mov $23, %rdx       # number of bytes

    syscall             # invoke operating system to do the write
 
	.data
format:	.string	"The value is %d\n"

