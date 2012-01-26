/*1. Write a C program to implement 'cp' command in linux.(Source and destination files should be taken from command line) */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


/* Example : mv data foo/ */

int main(int argc, char **argv) {

	int src;				/* file descriptor for source file */
	int dest;				/* file descriptor for destination file */

	struct stat src_stat_buf;	/* hold information about input file */
	struct stat dst_stat_buf;	/* hold information about destination file */

	char *destPath;
	off_t offset = 0;		/* byte offset used by sendfile */


	destPath = strcat(argv[2], argv[1]);
	printf("Command : sv %s %s\n", argv[1], destPath);

	/* check that source file exists and can be opened */
	src = open(argv[1], O_RDONLY);
	fstat(src, &src_stat_buf);

	/* open destination file */
	dest = open(destPath, O_WRONLY|O_CREAT, src_stat_buf.st_mode);
	fstat(dest, &dst_stat_buf);


	printf("Src modified time  %ld \n", src_stat_buf.st_mtime);
	printf("Dst modified time  %ld \n", dst_stat_buf.st_mtime);

	// big == new :)

	if(src_stat_buf.st_size==4096) {
		// Directory
		printf("Directory mode \n");
	} else {
		// File
		printf("Files mode \n");
		if (src_stat_buf.st_mtime > dst_stat_buf.st_mtime) {
			// Source new, replace
			/* copy file using sendfile */
			printf("Source file is newer. Replace\n");
			sendfile (dest, src, &offset, src_stat_buf.st_size);
		} else {
			printf("Dst file is newer. Do nothing\n");
		}
	}



	/* clean up and exit */
	close(dest);
	close(src);
}
