#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linked_list ll; 
struct linked_list {
    int order;
    int IsSel;
    ll* pnode;
};

#define N sizeof(ll)

int main(void)
{
    clock_t sta,end;
    double duration;
    int m,n,pm;//pm stands for the previous amounts
    ll *ta,*head,*tb;
    printf("PLZ input 'm n'\n"
           "m means amounts of monkeys\n"
           "n means counts\n");
    scanf("%d %d",&m,&n);
    if(n<1){printf("Error");return 1;}
    sta = clock();
    pm=m;
    head = (ta = (ll*)malloc(N));    
    head->IsSel=0;head->order=1;
    while (--m>=1) {
        tb = (ll*)malloc(N);
        tb->IsSel=0;tb->order=pm-m+1;
        ta->pnode=tb;
        ta=tb;tb=NULL;
    }
    ta->pnode=head;
    tb=head;
    while (pm>=1) {
        int pro=n;//pro stands for the process counts of n
        while (pro>1 | tb->IsSel) {
            if(!(pro>1 & tb->IsSel)) {
                pro--;
            }
            tb=tb->pnode;
        }
        printf("%d-->",tb->order);
        tb->IsSel=1;
        pm--; 
    }
    printf("Quit\n");
    end = clock();
    duration = (double)(end-sta) / CLOCKS_PER_SEC;
    printf("%f seconds",duration);
    return 0;
}