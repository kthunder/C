#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * 使用系统调用wait()
 *
 * 输出如下：
 * hello world (pid:1334)
 * hello, I am child (pid:1335)
 * hello, I am parent of 1335 (wc:1335) (pid:1334)
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
		printf("hello, I am child (pid:%d)\n",(int) getpid());
	} else
	{
        int wc = wait(NULL); //等待子进程结束
		printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int) getpid());
	}
	return 0;
}