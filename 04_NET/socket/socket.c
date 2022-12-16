#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void* server(void* arg)
{
    // 创建套接字
    int server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 将套接字和IP、端口绑定
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));	     // 每个字节都用0填充
    server_address.sin_family = AF_INET;		     // 使用IPv4地址
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // 具体的IP地址
    server_address.sin_port = htons(1234);		     // 端口
    bind(server_sock, (struct sockaddr*)&server_address, sizeof(server_address));

    // 进入监听状态，等待用户发起请求
    listen(server_sock, 20);

    // 接收客户端请求
    struct sockaddr_in client_address;
    socklen_t client_addr_size = sizeof(client_address);
    int client_sock = accept(server_sock, (struct sockaddr*)&client_address, &client_addr_size);

    // 向客户端发送数据
    char buffer[100] = {0};
    for (int i = 0; i < 30; ++i)
    {
	printf("%s now send a massage to client\n", (char*)arg);
	printf("%lu\n", pthread_self());
	sprintf(buffer, "hello client, this is index %d", i);
	write(client_sock, buffer, sizeof(buffer));
    }
    // 关闭套接字
    close(client_sock);
    close(server_sock);
}

void* client(void* arg)
{
    // 创建套接字
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // 向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));		// 每个字节都用0填充
    serv_addr.sin_family = AF_INET;			// 使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 具体的IP地址
    serv_addr.sin_port = htons(1234);			// 端口
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // 读取服务器传回的数据
    char buffer[100];
    for (int i = 0; i < 30; ++i)
    {
	read(sock, buffer, sizeof(buffer) - 1);
	printf("%s now get a massage from server, [index:%2d] : %s\n", (char*)arg, i, buffer);
	//        sleep(1);
    }

    // 关闭套接字
    close(sock);
}

int main()
{
    pthread_t th_server;
    pthread_t th_client;
    pthread_create(&th_server, NULL, server, "thread 0:");
    pthread_create(&th_client, NULL, client, "thread 1:");
    pthread_join(th_server, NULL);
    pthread_join(th_client, NULL);
    return 0;
}