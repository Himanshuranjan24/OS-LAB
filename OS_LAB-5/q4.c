#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
    pid_t x;
    x = fork();
    if (x == 0)
    {
        printf("Child Process\n");
        printf("getpid : %d, getppid : %d \n", getpid(), getppid());

        pid_t y;
        y = fork();
        if (y == 0)
        {
            printf("Child Process\n");
            printf("getpid : %d, getppid : %d \n", getpid(), getppid());
        }
        else
        {
            sleep(10);
        }
    }

    else
    {
        printf("Child Process\n");
        printf("getpid : %d, getppid : %d \n", getpid(), getppid());
        sleep(10);
    }
    return 0;
}