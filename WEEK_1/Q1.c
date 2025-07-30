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
       printf("i am child process.... \n");


    }
    else{
       printf("i am parent process ...\n");

    }
    return 0;
}


