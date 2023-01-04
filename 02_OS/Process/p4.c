#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
/**
 * 使用系统调用execvp()
 *
 * 输出如下：
 *
 * hello world (pid:1733)
 * hello, I am parent of 1734 (wc:1734) (pid:1733)
 *
 * 在文件p4.output中
 * hello, I am child (pid:1734)
 * 30  88 704 p3.c
 *
*/
int main(int argc, char const *argv[])
{
	printf("hello world (pid:%d)\n",(int) getpid());
	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr,"fork failed\n");
		exit(1);
	} else if ( rc == 0)
	{
		close(STDOUT_FILENO);
		open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		printf("hello, I am child (pid:%d)\n",(int) getpid());
		char *myargs[3];
		myargs[0] = strdup("wc");		// program: "wc" (word count)
		myargs[1] = strdup("p4.c");		// argument: file to count
		myargs[2] = NULL;				// marks end of array
		execvp(myargs[0], myargs);		// runs word count
		printf("this shouldn't print out");
	} else
	{
		int wc = wait(NULL); //等待子进程结束
		printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int) getpid());
	}
	return 0;
}
