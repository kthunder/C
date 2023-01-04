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
static int g_number_x = 0;
int main(int argc, char const *argv[])
{
    int number_x = 0;

	printf("hello world (pid:%d)\n",(int) getpid());

    number_x = 100;
    g_number_x = 100;

	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr,"fork failed\n");
		exit(1);
	} else if ( rc == 0)
	{
        g_number_x = 99;
        number_x = 99;
        printf("number_x:%d\ng_number_x:%d\n",number_x,g_number_x);
		printf("hello, I am child\n");
	} else
	{
        g_number_x = 98;
        number_x = 98;
		int wc = wait(NULL); //等待子进程结束
        printf("number_x:%d\ng_number_x:%d\n",number_x,g_number_x);
		printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int) getpid());
	}
	return 0;
}
