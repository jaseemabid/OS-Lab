/*

5.Write a C program to impelemnt a directory walk using opendir() and readdir()
  system calls. (All the file names(in the directory) should be printed as output.)		*/ 
  										

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv ) 
{
	DIR *dir;
	struct dirent *dirent;
	char *where = NULL;
	char *asd[100];

	if (argc == 1) where = get_current_dir_name();
	else where = argv[1];

	if (NULL == (dir = opendir(where))) 
	{
		fprintf(stderr,"%d (%s) opendir %s failed\n", errno, strerror(errno), where);
		return 2;
	}
	while (NULL != (dirent = readdir(dir))) 
	{
		printf("%s\n", dirent->d_name);
	}
	closedir(dir);
	return 0;
}
