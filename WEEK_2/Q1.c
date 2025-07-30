/*

Write a program to open a directory and list its contents. (use opendir(), readdir(), closedir() )


*/


#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>

int main(){
    DIR *dir;
    struct dirent * entry;

    dir=opendir(".");
    if(dir==NULL){
           printf("unable to open directory .....\n");
           return 1;
    }
    printf("contents of the current directory ....\n");
    while((entry=readdir(dir))!=NULL)
    {
        printf("%s\n",entry->d_name);

    }
    closedir(dir);

    return 0;
}
