/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include "lab0.h"

extern int start_syscallsummary;

/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{
	STATWORD ps;    
	unsigned long start_timer = ctr1000;
	int syscall_number = 18;
	if (start_syscallsummary == 1) {
		syscallsummary_table[currpid][syscall_number].SysCall_Name = "sys_sleep";
		syscallsummary_table[currpid][syscall_number].frequency += 1;
	}
	if (n<0 || clkruns==0) {
		syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
		return(SYSERR);
	}
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);
	syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
	return(OK);
}
