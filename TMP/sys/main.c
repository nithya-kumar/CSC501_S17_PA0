/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include "lab0.h"

void halt();

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
prch(c)
char c;
{
        sleep(5);
}
int main()
{
        kprintf("\n\nHello World, Xinu lives\n\n");
        int prX;
        long a = 0xaabbccdd;
        kprintf("Value after bit manipulation:0x%08x\n", zfunction(a));
        printsegaddress();
        printtos();
        printprocstks(1);
        syscallsummary_start();
        resume(prX = create(prch,2000,20,"proc X",1,'A'));
        sleep(10);
        syscallsummary_stop();
        printsyscallsummary();
        return 0;
}
