#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linked_list ll; 
struct linked_list {
    int order;
    ll* pnode;
    ll* lnode;
};

#define N sizeof(ll)

int main(void)
{
    clock_t sta,end;
    double duration;
    int m,n,pm;//pm stands for the previous m
    ll *ta,*head,*tb;
    printf("PLZ input 'm n'\n"
           "m means amounts of monkeys\n"
           "n means counts\n");
    scanf("%d %d",&m,&n);
    if(n<1){printf("Error");return 1;}
    sta = clock();
    pm=m;
    head = (ta = (ll*)malloc(N));    
    head->order=1;
    while (--m>=1) {
        tb = (ll*)malloc(N);
        tb->order=pm-m+1;
        ta->pnode=tb;tb->lnode=ta;
        ta=tb;tb=NULL;
    }
    ta->pnode=head;head->lnode=ta;
    tb=head;
    while (pm>=1) {
        int pro=(n<=pm)?n:(n%pm)?n%pm:pm;//pro n,delete the circle
        while(--pro>0) {
            tb=tb->pnode;
        }
        printf("%d-->",tb->order);
        ll *tt;
        tt=tb->lnode->pnode=tb->pnode;
        tb->pnode->lnode=tb->lnode;
        free(tb);
        tb=tt;
        pm--; 
    }
    printf("Quit\n");
    end = clock();
    duration = (double)(end-sta) / CLOCKS_PER_SEC;
    printf("%f seconds",duration);
    return 0;
}