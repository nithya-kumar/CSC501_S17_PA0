/* receive.c - receive */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include "lab0.h"

extern int start_syscallsummary;

/*------------------------------------------------------------------------
 *  receive  -  wait for a message and return it
 *------------------------------------------------------------------------
 */
SYSCALL	receive()
{
	STATWORD ps;    
	struct	pentry	*pptr;
	WORD	msg;
	unsigned long start_timer = ctr1000;
	int syscall_number = 6;
	if (start_syscallsummary == 1) {
		syscallsummary_table[currpid][syscall_number].SysCall_Name = "sys_receive";
		syscallsummary_table[currpid][syscall_number].frequency += 1;
	}
	disable(ps);
	pptr = &proctab[currpid];
	if ( !pptr->phasmsg ) {		/* if no message, wait for one	*/
		pptr->pstate = PRRECV;
		resched();
	}
	msg = pptr->pmsg;		/* retrieve message		*/
	pptr->phasmsg = FALSE;
	restore(ps);
	syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
	return(msg);
}
