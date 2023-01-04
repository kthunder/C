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
	int rc = fork();

	if (rc < 0)
	{
		fprintf(stderr, "failed\n");
		exit(1);
	}

	else if (rc == 0)
	{
		printf("----child process----\n");
	}
	else
	{
		// int wc = wait(NULL); //等待子进程结束
		printf("----parent process----\n");
	}
	return 0;
}
