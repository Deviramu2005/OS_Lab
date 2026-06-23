#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sock;
    char buffer[100];

    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr *)&server, sizeof(server));

    recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);

    printf("Received: %s\n", buffer);

    close(sock);

    return 0;
}
