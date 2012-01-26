#include<stdlib.h>
#include<unistd.h>
int main()
{
	int fd[2], ret;
	pipe(fd);
	ret = fork();
	if(ret>0) {
		close(1);
		dup(fd[1]);
		close(fd[0]);
		close(fd[1]);
		execlp("ls","ls",NULL);
	} else if(ret==0) {
		close(0);
		dup(fd[0]);
		close(fd[0]);
		close(fd[1]);
		execlp("sort","sort",NULL);
	}
	return 0;
}
