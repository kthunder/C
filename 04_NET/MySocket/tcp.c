#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <assert.h>
#include <pthread.h>

void* client(void* arg)
{
	int ret;
	// 1.创建客户端套接字（描述符\句柄）
	int client_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	assert(client_sock >= 0);
	// 2.连接服务端
	struct sockaddr_in serv_addr;
	bzero(&serv_addr, sizeof(struct sockaddr_in));		// 置0
	serv_addr.sin_family = AF_INET;						// ipv4
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // ip地址
	serv_addr.sin_port = htons(6666);					// 端口号
	ret = connect(client_sock, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr_in));
	assert(ret == 0);
	// 3.读取数据
	char buffer[100] = {0};
	read(client_sock, buffer, 99);
	printf("client recevie: %s\n", buffer);
	// 4.关闭套接字
	close(client_sock);
}

void* server(void* arg)
{
	int ret;
	// 1.创服务端建套接字（描述符\句柄）
	int server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	assert(server_sock != 0);
	// 2.将套接字和ip、端口绑定
	struct sockaddr_in serv_addr;
	bzero(&serv_addr, sizeof(struct sockaddr_in));								 // 置0
	serv_addr.sin_family = AF_INET;												 // ipv4
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");							 // ip地址
	serv_addr.sin_port = htons(6666);											 // 端口号
	ret = bind(server_sock, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr_in)); // 创建连接
	printf("%d\n", ret);
	assert(ret == 0);
	// 3.开始监听端口，等待客户端连接
	ret = listen(server_sock, 100);
	assert(ret == 0);
	// 4.接受客户端的连接，获取客户端的套接字
	struct sockaddr_in client_addr;
	socklen_t addr_len = sizeof(struct sockaddr_in);
	int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_len);
	assert(client_sock >= 0);
	// 5.发送数据
	char* str = "hello, this message is from server!";
	write(client_sock, str, strlen(str));
	printf("server send: %s\n", str);
	// 6.关闭套接字
	close(client_sock);
	close(server_sock);
}

int main(int argc, char const* argv[])
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread2, NULL, server, "this is server");
	sleep(1);
	pthread_create(&thread1, NULL, client, "this is client");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
