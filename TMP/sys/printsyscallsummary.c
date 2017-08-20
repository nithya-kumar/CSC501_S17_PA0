#include<conf.h>
#include<stdio.h>
#include "lab0.h"

int start_syscallsummary = 0;

void syscallsummary_start() {
	start_syscallsummary = 1;
}

void syscallsummary_stop() {
	start_syscallsummary = 0;
}

void printsyscallsummary() {
	int process;	
	int sys_calls;	
	kprintf("\nTask 5: printsyscallsummary");
	for(process = 1; process < NPROC; process++) {
		if(process_exist[process] == 1) {
			kprintf("\nProcess [pid:%d]", process);
			for(sys_calls = 0; sys_calls < 27; sys_calls++) {
				if(syscallsummary_table[process][sys_calls].frequency > 0) {
					kprintf("\n\t\tSyscall: %s, count: %d, average execution time: %lu (ms)", syscallsummary_table[process][sys_calls].SysCall_Name, syscallsummary_table[process][sys_calls].frequency, (syscallsummary_table[process][sys_calls].avg_exectime/syscallsummary_table[process][sys_calls].frequency));
				}
			}
		}
	}
}
