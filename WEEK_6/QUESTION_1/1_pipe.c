#include<stdio.h>
#include<unistd.h>
int main(){
    int p[2];
    int returnstatus;
    char writing[2][25]={"hello","word"};
    char readmsg[25];
   
    returnstatus=pipe(p);
    if(returnstatus==1){
        printf("pipe not created");
    }
    printf("\n writing started %s", writing[0]);
    write(p[1],writing[0],sizeof(writing[0]));
    read(p[0],readmsg,sizeof(readmsg));
    printf("\n Reading from pipe-msg 1 %s\n",readmsg);
    
    return 0;
}