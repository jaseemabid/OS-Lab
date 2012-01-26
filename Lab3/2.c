/* 2. Write a C program to read 'n' characters from position 't' of a given file. */


#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main (int argc, char* argv[])
{
	int readfd;
	struct stat stat_buf;
	readfd = open (argv[1], O_RDONLY); 				// Open the input file.
	fstat (readfd, &stat_buf);						// Stat the input file to obtain its size. 
	int p, n;
	off_t off_set1;
	printf("\nEnter pos and number : ");
	scanf("%d %d", &p, &n);
	off_set1 =  lseek(readfd, p, 0) ; 				// Move to position
	off_set1--;
	sendfile (1, readfd, &off_set1, n);		
	printf("\n\n");
	close (readfd);									// Close file descriptors.
	return 0;
}

