/* wait.c - wait */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include "lab0.h"

extern int start_syscallsummary;
/*------------------------------------------------------------------------
 * wait  --  make current process wait on a semaphore
 *------------------------------------------------------------------------
 */
SYSCALL	wait(int sem)
{
	STATWORD ps;    
	struct	sentry	*sptr;
	struct	pentry	*pptr;
	unsigned long start_timer = ctr1000;
	int syscall_number = 26;
	if (start_syscallsummary == 1) {
		syscallsummary_table[currpid][syscall_number].SysCall_Name = "sys_wait";
		syscallsummary_table[currpid][syscall_number].frequency += 1;
	}
	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
		syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
		return(SYSERR);
	}
	
	if (--(sptr->semcnt) < 0) {
		(pptr = &proctab[currpid])->pstate = PRWAIT;
		pptr->psem = sem;
		enqueue(currpid,sptr->sqtail);
		pptr->pwaitret = OK;
		resched();
		restore(ps);
		syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
		return pptr->pwaitret;
	}
	restore(ps);
	syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
	return(OK);
}
