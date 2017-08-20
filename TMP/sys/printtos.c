#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
static unsigned long *esp;
static unsigned long *ebp;

void printtos()
{
        asm("movl %esp,esp");
        asm("movl %ebp,ebp");
		kprintf("\nTask 3 - printtos\n");
        kprintf("Before[0x%08x]: 0x%08x\n", ebp + 2, *(ebp + 2));
        kprintf("After[0x%08x]: 0x%08x\n", ebp, *ebp);
        kprintf("Contents of four stack locations below the top of the stack:\n");
        kprintf("\t\telement[0x%08x]: 0x%08x\n",esp + 1, *(esp + 1));
        kprintf("\t\telement[0x%08x]: 0x%08x\n",esp + 2, *(esp + 2));
        kprintf("\t\telement[0x%08x]: 0x%08x\n",esp + 3, *(esp + 3));
        kprintf("\t\telement[0x%08x]: 0x%08x\n",esp + 4, *(esp + 4));
}
