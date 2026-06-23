#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
        printf("Hello from Child Process\n");
    }
    else
    {
        printf("Hello from Parent Process\n");
    }

    return 0;
}
