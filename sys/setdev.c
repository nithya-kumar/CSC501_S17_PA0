/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include "lab0.h"

extern int start_syscallsummary;

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	short	*nxtdev;
	unsigned long start_timer = ctr1000;
	int syscall_number = 13;
	if (start_syscallsummary == 1) {
		syscallsummary_table[currpid][syscall_number].SysCall_Name = "sys_setdev";
		syscallsummary_table[currpid][syscall_number].frequency += 1;
	}

	if (isbadpid(pid))
		return(SYSERR);
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
	return(OK);
}
