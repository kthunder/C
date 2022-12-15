#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * 使用系统调用fork()
 *
 * 输出如下：
 * 	hellow world (pid:1047)
 * 	hello, I am parent of 1048 (pid:1047)	//父进程输出
 * 	hello, I am child (pid:1048)			//子进程输出，子进程的rc等于0
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
		printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
	}
	return 0;
}