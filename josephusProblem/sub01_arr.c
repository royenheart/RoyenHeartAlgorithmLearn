#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

static int arr[N]={0};

int main(void)
{
    clock_t sta,end;
    double duration;
    int m,n,pos=0,pm;//pm means previous m
    printf("PLZ input 'm n'\n"
           "m means amounts of monkeys\n"
           "n means counts\n");
    scanf("%d %d",&m,&n);
    sta = clock();
    if(n<1){printf("Error");return 1;}
    pm=m;
    while (m>=1) {
        int pro=n;//pro stands for the process counts of n
        while (pro>1 | arr[pos]) {
            if(!(pro>1 & arr[pos])) {
                pro--;
            }
            pos=(pos+1)%pm;
        }
        printf("%d-->",pos+1);
        arr[pos]=1;
        m--; 
    }
    printf("Quit\n");
    end = clock();
    duration = (double)(end-sta) / CLOCKS_PER_SEC;
    printf("%f seconds",duration);
    return 0;
}