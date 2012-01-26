/*1. Write a C program to implement 'cp' command in linux.(Source and destination files should be taken from command line) */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int src;               /* file descriptor for source file */
	int dest;              /* file descriptor for destination file */
	struct stat stat_buf;  /* hold information about input file */
	off_t offset = 0;      /* byte offset used by sendfile */

	/* check that source file exists and can be opened */
	src = open(argv[1], O_RDONLY);
	/* get size and permissions of the source file */
	fstat(src, &stat_buf);
	/* open destination file */
	dest = open(argv[2], O_WRONLY|O_CREAT, stat_buf.st_mode);
	/* copy file using sendfile */
	sendfile (dest, src, &offset, stat_buf.st_size);
	/* clean up and exit */
	close(dest);
	close(src);
}
