#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main ()
{
    {
        fork();
        fork();
        printf("os \n");
    }
    {
        fork();
        printf("Lab \n");
    }
}
