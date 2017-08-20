#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
extern long etext, edata;
void printsegaddress(void) {
	kprintf("\nTask 2 - printsegaddress\n");
	kprintf("Printing the addresses indicating the end of the text, data, and BSS segments of the Xinu OS\n");
	kprintf("Current: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n", &etext, *(&etext), &edata, *(&edata), &end, *(&end));
	kprintf("Preceding: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n", &etext - 1, *(&etext - 1), &edata - 1, *(&edata - 1), &end - 1, *(&end - 1));
	kprintf("After: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n", &etext  + 1, *(&etext + 1), &edata + 1, *(&edata + 1), &end + 1, *(&end + 1));
}
