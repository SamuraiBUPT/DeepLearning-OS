.set IRQ_BASE 0x20

.section .text

.extern _ZN16interruptManager15handleInterruptEhj

.macro HandleException num
.global _ZN16interruptManager16handleInterruptException\num\()Ev
    movb $\num, (interruptnumber)
    jmp int_bottom
.endm

.macro HandleInterruptRequest num
.global _ZN16interruptManager26handleInterruptRequest\num\()Ev
    movb $\num+IRQ_BASE, (interruptnumber)
    jmp int_bottom
.endm

HandleInterruptRequest 0x00
HandleInterruptRequest 0x01

int_bottom:
    pusha
    pushl %ds
    pushl %es
    pushl %fs
    pushl %gs


    pushl %esp
    push (interruptnumber)
    call _ZN16interruptManager15handleInterruptEhj
    movl %eax, %esp

    popl %gs
    popl %fs
    popl %es
    popl %ds
    popa

    iret


.data
    interruptnumber: .byte 0