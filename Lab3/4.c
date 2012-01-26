/*Write a C program to print the system statistics like system uptime, 
  total RAM space, free RAM space, process count, page size , size of 
  user memory using sysinfo() system call.				*/

/* struct sysinfo {
               long uptime;             // Seconds since boot  
               unsigned long loads[3];  // 1, 5, and 15 minute load averages  
               unsigned long totalram;  // Total usable main memory size  
               unsigned long freeram;   // Available memory size  
               unsigned long sharedram; // Amount of shared memory  
               unsigned long bufferram; // Memory used by buffers  
               unsigned long totalswap; // Total swap space size  
               unsigned long freeswap;  // swap space still available  
               unsigned short procs;    // Number of current processes  
               unsigned long totalhigh; // Total high memory size  
               unsigned long freehigh;  // Available high memory size  
               unsigned int mem_unit;   // Memory unit size in bytes  
               char _f[20-2*sizeof(long)-sizeof(int)]; // Padding for libc5  
           };
*/


#include<stdio.h>
#include<errno.h>
#include<sys/sysinfo.h>
#include<unistd.h>

int main()
{
	struct sysinfo info;
	sysinfo(&info);
	int pagesize;
	pagesize = getpagesize();
	printf("\n\n \tSystem info  \n\n");
	long hrs, mins, secs, tram, fram, usm;
	secs = info.uptime;
	hrs = secs/3600;
	secs = secs-hrs*3600;
	mins = info.uptime/60;
	secs = secs-mins*60;
	tram = info.totalram/(1024*1024);
	fram = info.freeram/(1024*1024);
	usm  = info.totalhigh/(1024*1024);	
	printf("Uptime			: %d hrs %d mins %d secs ( a total of %d seconds )\n", (int)hrs, (int)mins, (int)secs, (int)info.uptime);
	printf("Total Ram space 	: %d bytes ( %d MB ) \n", (int)info.totalram, (int)tram );
	printf("Free Ram space 		: %d bytes ( %d MB ) \n", (int)info.freeram, (int)fram );
	printf("Process Count 		: %d        \n", (int)info.procs );
	printf("Page size   	    	: %d bytes  \n", pagesize);
	printf("Size of user memory 	: %d bytes ( %d MB ) \n", (int)info.totalhigh, (int)usm);
	return 0;
}
