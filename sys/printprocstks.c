#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

static unsigned long *esp;
void printprocstks(int priority)
{
	struct pentry *process;
	kprintf("\nTask 4 - printprocstks\n");
	printf("Printing process stacks\n");
	int i;
	for(i = 0; i < NPROC; i++) {
		process = &proctab[i];
		if(process -> pstate != PRFREE) {
			if(process -> pprio > priority) {
				kprintf("Process [proc %s]\n", process -> pname);
				kprintf("\t\tpid: %d\n",i);
				kprintf("\t\tpriority: %d\n",process -> pprio);	
				kprintf("\t\tbase: 0x%08x\n",process -> pbase);
				kprintf("\t\tlimit: 0x%08x\n",process -> plimit);
				kprintf("\t\tlen: %d\n",process -> pstklen);
				
				if(process -> pstate == PRCURR) {
					asm("movl %esp, esp");
				}
				else {
					esp = (unsigned long *)process -> pesp;
				}
				kprintf("\t\tpointer: 0x%08x\n",esp);
			}
		}
	}
}
