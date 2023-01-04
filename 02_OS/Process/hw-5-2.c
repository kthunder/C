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
	char in_buffer[1024] = "0123456789abcdefghijklmnopqrsyuvwxyz";
	char out_buffer[1024];
	int fd = open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

	// write(fd, in_buffer, 10);

	int rc = fork();

	if (rc < 0 || fd < 0)
	{
		fprintf(stderr, "failed\n");
		exit(1);
	}

	else if (rc == 0)
	{
		printf("----child process----\n");
		printf("write res:%ld\n", write(fd, in_buffer, 10));
		printf("read res:%ld\n", read(fd, out_buffer, 10));

		printf("fd:%d buffer:%s\n", fd, out_buffer);
	}
	else
	{
		// int wc = wait(NULL); //等待子进程结束
		printf("----parent process----\n");
		// write(fd,in_buffer,10);
		printf("write res:%ld\n", write(fd, in_buffer, 10));
		printf("read res:%ld\n", read(fd, out_buffer, 10));

		printf("fd:%d buffer:%s\n", fd, out_buffer);
	}
	return 0;
}
