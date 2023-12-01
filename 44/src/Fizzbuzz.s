.data
    n: .space 4
    fs: .asciz "%d"
    fp: .asciz "Select a number: "
    fizzbuzz: .asciz "FizzBuzz\n"
    fizz: .asciz "Fizz\n"
    buzz: .asciz "Buzz\n"
.text
.globl main
main:
    pushl $fp
    call printf
    addl $4, %esp

    # Read n
    pushl $n
    pushl $fs
    call scanf
    addl $8, %esp

    # Check if n is divisible by 3
    movl n, %eax
    movl $3, %ebx
    movl $0, %edx
    divl %ebx

    # If it is, jump to et_fizz
    cmpl $0, %edx
    je et_fizz

    # If it isn't, check if n is divisible by 5
    movl n, %eax
    movl $5, %ebx
    movl $0, %edx
    divl %ebx

    # If it is, jump to et_buzz
    cmpl $0, %edx
    je et_buzz

    # If it isn't, print n
    pushl n
    pushl $fs
    call printf
    addl $8, %esp
    jmp et_exit

et_fizz:
    # n is divisible by 3
    # Now check if n is divisible by 5
    movl n, %eax
    movl $5, %ebx
    movl $0, %edx
    divl %ebx

    # If it is, jump to et_fizzbuzz
    cmpl $0, %edx
    je et_fizzbuzz

    # If it isn't, print fizz
    pushl $fizz
    call printf
    addl $4, %esp
    jmp et_exit

et_buzz:
    # We know that if we get here, n is not divisible by 3
    # But it is divisible by 5
    # So print buzz
    pushl $buzz
    call printf
    addl $4, %esp
    jmp et_exit

et_fizzbuzz:
    # n is divisible by 3 and 5
    # So print fizzbuzz
    pushl $fizzbuzz
    call printf
    addl $4, %esp

et_exit:
    # Call fflush(stdout)
    pushl $0
    call fflush
    addl $4, %esp

    # Call exit(0)
    movl $1, %eax
    xorl %ebx, %ebx
    int $0x80
