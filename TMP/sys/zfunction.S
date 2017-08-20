        .text
.globl zfunction
        .type   zfunction, @function
.LC0:
        .string "\nTask 1 - zfunction\n"
	.text
zfunction:
        pushl   %ebp
        movl    %esp, %ebp
        pushl $.LC0
        call kprintf
	movl    $0xffc01fff, %eax
        andl    %eax, 8(%ebp)
        movl    8(%ebp), %eax
        sall    $4, %eax
        leave
        ret
        .size   zfunction, .-zfunction
