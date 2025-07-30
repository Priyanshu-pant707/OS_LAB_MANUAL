/*
Write a program to create child process which will list all the files present in your system. Make
 sure that parent process waits until child has not completed its execution. (use wait(), exit())
 What will happen if parent process dies before child process? Illustrate it by creating one more
 child of parent process.

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t id1, id2;

    id1 = fork();

    if (id1 < 0)
    {
        printf("fork failed....\n");
        exit(1);
    }
    else if (id1 == 0)
    {
        printf("child 1 is running .....\n");
        printf("child 1 (pid: %d) and parent (parent pid : %d)\n", getpid(), getppid());

        //
    }
    else
    {
        printf("parent 1 (pid : %d) is running and waiting for child 1 to finish.... \n", getpid());
        wait(NULL);

        printf("parent 1 is running and creating new fork..... \n");
        id2 = fork();

        if(id2<0){
            printf("fork failed....");
            exit(1);
        }else if(id2==0){
            printf("child 2 is running .....\n");
            printf("child 2 pid : %d \n",getpid());
            printf("parent pid (in child 2) : %d \n",getppid());
            sleep(3);
            printf("child 2 (pid : %d) after parent exit ,parent id (pid : % d)\n",getpid(),getppid());
            
        }
        else{
            printf("parent 2 is running....\n");
            printf("parent 2 p_id : %d \n",getpid());
            exit(0);
        }
    }
    return 0;
}
