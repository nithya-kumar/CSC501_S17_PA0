/* freemem.c - freemem */

#include <conf.h>
#include <kernel.h>
#include <mem.h>
#include <stdio.h>
#include <proc.h>
#include "lab0.h"

extern int start_syscallsummary;
/*------------------------------------------------------------------------
 *  freemem  --  free a memory block, returning it to memlist
 *------------------------------------------------------------------------
 */
SYSCALL	freemem(struct mblock *block, unsigned size)
{
	STATWORD ps;    
	struct	mblock	*p, *q;
	unsigned top;

	unsigned long start_timer = ctr1000;
	int syscall_number = 0;
	if (start_syscallsummary == 1) {
		syscallsummary_table[currpid][syscall_number].SysCall_Name = "sys_freemem";
		syscallsummary_table[currpid][syscall_number].frequency += 1;
	}

	if (size==0 || (unsigned)block>(unsigned)maxaddr
	    || ((unsigned)block)<((unsigned) &end)) {
		syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
		return(SYSERR);
	}
	size = (unsigned)roundmb(size);
	disable(ps);
	for( p=memlist.mnext,q= &memlist;
	     p != (struct mblock *) NULL && p < block ;
	     q=p,p=p->mnext )
		;
	if (((top=q->mlen+(unsigned)q)>(unsigned)block && q!= &memlist) ||
	    (p!=NULL && (size+(unsigned)block) > (unsigned)p )) {
		restore(ps);
		syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
		return(SYSERR);
	}
	if ( q!= &memlist && top == (unsigned)block )
			q->mlen += size;
	else {
		block->mlen = size;
		block->mnext = p;
		q->mnext = block;
		q = block;
	}
	if ( (unsigned)( q->mlen + (unsigned)q ) == (unsigned)p) {
		q->mlen += p->mlen;
		q->mnext = p->mnext;
	}
	restore(ps);
	syscallsummary_table[currpid][syscall_number].avg_exectime += ctr1000 - start_timer;
	return(OK);
}
