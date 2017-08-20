#ifndef _LAB0_H_
#define _LAB0_H_

#include <stdio.h>

extern unsigned long ctr1000;
extern int process_exist[];

struct procsummary	{
	char *SysCall_Name;
	
	unsigned int frequency;
	 
	unsigned long avg_exectime;
	
}syscallsummary_table[100][27];

extern long zfunction(long);
extern void printsegaddress();
extern void printprocstks(int);
extern void printtos();
extern void printsyscallsummary();
extern void syscallsummary_start();
extern void syscallsummary_stop();
#endif
