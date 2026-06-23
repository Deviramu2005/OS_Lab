#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
    char msg[100];

    pipe(fd);

    if(fork()==0)
    {
        read(fd[0], msg, sizeof(msg));
        printf("Child received: %s\n", msg);
    }
    else
    {
        write(fd[1], "Hello Child", 12);
    }

    return 0;
}
