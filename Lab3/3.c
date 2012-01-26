/*
3. Write a C function 'fsize' which prints the size of a given file (in 
	linux, a directory is also a kind of file). If the file is a directory
	make a directory walk to to apply 'fsize' on all files in it. The 
	output in this case should be the name(s) of files in the directory 
	and its size.
*/

 /* 
 struct stat {
	dev_t	st_dev;		// ID of device containing file 
	ino_t	st_ino;		// inode number 
	mode_t	st_mode;	// protection 
	nlink_t	st_nlink;	// number of hard links 
	uid_t	st_uid;		// user ID of owner
	gid_t	st_gid;		// group ID of owner 
	dev_t	st_rdev;	// device ID (if special file) 
	off_t	st_size;	// total size, in bytes 
	blksize_t st_blksize;	// blocksize for file system I/O 
	blkcnt_t st_blocks;	// number of 512B blocks allocated 
	time_t	st_atime;	// time of last access 
	time_t	st_mtime;	// time of last modification 
	time_t	st_ctime;	// time of last status change 
			};
*/


#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include <string.h>



int main (int argc, char* argv[])
{
	int readfd, temp;
	struct stat stat_buf, temps;
	off_t offset = 0;
		DIR *dir;
		struct dirent *dirent;
		char *loc = NULL;
		
	readfd = open (argv[1], O_RDONLY); 													// Open the input file.
	fstat (readfd, &stat_buf);
	if(stat_buf.st_size==4096)															// Directory
	{
		printf("\nThe entered file is a Directory. Performing Directory walk...\n");
		loc = argv[1];

		if ((dir = opendir(loc)) == NULL ) 
		{
			fprintf(stderr,"%d (%s) opendir %s failed\n", errno, strerror(errno), loc);
			return 2;
		}
		
		while ((dirent = readdir(dir)) != NULL) 
		{
			temp = open (dirent->d_name, O_RDONLY); 									// Open the input file.
			fstat (temp, &temps);
			if(temps.st_size!=4096)
			printf("\n%s Size = %d", dirent->d_name, temps.st_size);
			else printf("\n%s - Directory ", dirent->d_name);
		}
		closedir(dir);
	}
	else 																				// File
	{																					// Stat the input file to obtain its size. 
		offset = stat_buf.st_size;														// Prints the size for files.
		printf("\nSize = %d\n", offset);
	}
	close (readfd);																		// Close file descriptors.
	return 0;
}

