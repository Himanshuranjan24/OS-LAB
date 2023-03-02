 #include<stdio.h>
 #include<unistd.h>
 #include<stdlib.h>
 #include<sys/types.h>
 int main()
 {
     pid_t x;
     x=fork();
     if(x==0)
     {
         printf("child process \n");
         printf("getpid : %d, grtpid : %d \n", getpid(), getppid());
     }
     else{
         printf("parent process \n");
         printf("getpid : %d, getppid : %d \n",getpid(),getppid());
         sleep(5);
     }
     return 0;
     }
 
