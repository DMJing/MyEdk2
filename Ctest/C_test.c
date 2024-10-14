/****************************************************
*test some C demo code ,don't need base on UEFI arch
*Author:dajing
*****************************************************/
#define DEMO3


#ifdef DEMO1 //print loop

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
#endif


#ifdef DEMO2 //C learning
/*
## operator classification
arithmetic operators:+ - * / % += -+ *= /= %=
relational operator:> < == >= <= !=
Logical Operators:&& || !
bitwise operators: & | ~
conditional operator:A?B:C
comma operator: ,   A=(5,6) =>A=6
increment/decrement operator: ++ --


*/

#include <stdio.h>
#include <stdlib.h>

int a= 10;
int b = 100;
int *q = NULL;

void func(int **p)
{
    printf("func:\tp=%d\t&p=%d\n",p,&p);     //note:3
    *p = &b;
    printf("func:\tp=%d\t&p=%d\n",p,&p);     //note:4
}

int main()
{
    printf("&a=%d\t&b=%d\t&q=%d\n",&a,&b,&q);   //note:1
    q = &a;
    printf("*q=%d\tq=%d\t&q=%d\n",*q,q,&q);     //note:2
    func(&q);
    printf("*q=%d\tq=%d\t&q=%d\n",*q,q,&q);     //note:5

    return 0;
}


#endif

#ifdef DEMO3 //test h file

#include <stdio.h>
#include <stdlib.h>
#include "test_h/aa.h"

int main()
{
    int a =6;
    bb(a);
    printf("hello\n");
}



#endif