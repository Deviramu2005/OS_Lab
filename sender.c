#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sock;

    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sock,
           "Hello UDP",
           10,
           0,
           (struct sockaddr *)&server,
           sizeof(server));

    close(sock);

    return 0;
}
