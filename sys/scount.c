/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <proc.h>
#include <stdio.h>
#include "lab0.h"
extern int start_syscallsummary;

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
extern	struct	sentry	semaph[];
	unsigned long start_timer = ctr1000;
	int syscall_number = 10;
	if (start_syscallsummary == 1) {
		syscallsummary_table[currpid][syscall_number].SysCall_Name = "sys_scount";
		syscallsummary_table[currpid][syscall_number].frequency += 1;
	}

	if (isbadsem(sem) || semaph[sem].sstate==SFREE) {
		syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
		return(SYSERR);
	}
	syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
	return(semaph[sem].semcnt);
}
