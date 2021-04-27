//只考虑最后出列的人的情况下
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10001

static int f[N]={0};

int main(void)
{
    int m,n,i=2;
    clock_t sta,end;
    double duration;
    printf("PLZ input 'm n'\n"
           "m means amounts of monkeys\n"
           "n means counts\n");
    scanf("%d %d",&m,&n);
    sta = clock();
    //运用递推
    if(n<1){printf("Error");return 1;}
    for(;i<=m;i++) {
        f[i]=(f[i-1]+n) % i;
    }
    printf("The last quit number is %d\n",f[m]+1);
    end = clock();
    duration = (double)(end-sta) / CLOCKS_PER_SEC;
    printf("%f seconds",duration);
    return 0;
}