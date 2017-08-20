/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include "lab0.h"

extern int start_syscallsummary;

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	unsigned long start_timer = ctr1000;
	int syscall_number = 2;
	if (start_syscallsummary == 1) {
		syscallsummary_table[currpid][syscall_number].SysCall_Name = "sys_getpid";
		syscallsummary_table[currpid][syscall_number].frequency += 1;
	}
	syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
	return(currpid);
}
