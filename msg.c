#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message
{
    long type;
    char text[100];
};

int main()
{
    struct message msg;

    int msgid = msgget(1234, 0666 | IPC_CREAT);

    msg.type = 1;

    strcpy(msg.text, "Hello Queue");

    msgsnd(msgid, &msg, sizeof(msg.text), 0);

    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

    printf("Message: %s\n", msg.text);

    return 0;
}
