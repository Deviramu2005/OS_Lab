#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    mkfifo("myfifo", 0666);

    int fd = open("myfifo", O_WRONLY);

    write(fd, "Hello FIFO", 11);

    close(fd);

    return 0;
}

