#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h> 
int main() 
{ 
    int pid; 
  
    for (int i = 0; i < 4; i++) { 
  
        // Fork a child process 
        pid = fork(); 
  
        if (pid == 0) { 
            printf("child process with ID %d and"
                   " parent process id is %d \n", 
                   getpid(), getppid()); 
            break; 
        } 
    } 
    return 0; 
}