/*
Write a program to create a child process using system call fork(). 
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

    pid_t p_id;
    p_id=fork();

    if(p_id<0){
        printf("fork failed");
        return 1;
    }
    else if(p_id==0){
        printf("running child process \n");
        printf("child p_id  :%d \n",getpid());
        printf("parent p_id  :%d \n",getppid());


    }
    else{
        printf("running parent process \n");
        printf("parent p_id :%d \n",getpid());
        printf("child id : %d \n",p_id);
    }
    return 0;
}