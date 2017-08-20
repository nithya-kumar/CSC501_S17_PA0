/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <proc.h>
#include <stdio.h>
#include "lab0.h"

extern int start_syscallsummary;
extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    /* long	now; */

	/* FIXME -- no getutim */
	unsigned long start_timer = ctr1000;
	int syscall_number = 4;
	if (start_syscallsummary == 1) {
		syscallsummary_table[currpid][syscall_number].SysCall_Name = "sys_gettime";
		syscallsummary_table[currpid][syscall_number].frequency += 1;
	}
	syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
    return OK;
}

