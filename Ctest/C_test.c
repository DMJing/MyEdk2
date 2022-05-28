/****************************************************
*test some C demo code ,don't need base on UEFI arch
*Author:dajing
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
//TODO:a while(1) loop,when another function finished, break while(1)  
int *flag = NULL;

void print_loop()
{
    int Index = 0;
    while(1){
        printf("\r");
        for(Index = 0;Index<6; Index++){
        printf("=>");
        fflush(stdout);
        usleep(100000);
        }
        printf("\r            ");
        fflush(stdout);
        usleep(100000);
    }
}

void print_loop2()
{

    int i=0;
    char bar[101];
    const char* lable="|/-\\";//打印旋转的图标
    while(i<=100)
    {
        bar[i]='\0';
        printf("[%-100s] [%c] [%d%%]\r",bar,lable[i%4],i);
        fflush(stdout);
        bar[i]='#';
        i++;
        usleep(100000);
    }
    printf("\n");
}


int main(){
    //printf("hello world \r\n");
    print_loop2();
    return 0;
}
