#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lis_poly pol;
struct lis_poly {
    double cof;
    double inx;
    pol *pnode;
};

#define N sizeof(pol)

pol *a,*ahead=NULL,*b,*bhead=NULL;

int assign(pol *need,double cof,double inx,pol *p);
pol* create_pol(int many);

int main(void)
{
    int AmOfA,AmOfB;
    clock_t end,sta;
    printf("how many of A\n");
    scanf("%d",&AmOfA);
    printf("how many of B\n");
    scanf("%d",&AmOfB);
    a = ahead = create_pol(AmOfA);
    b = bhead = create_pol(AmOfB);
    sta = clock();
    printf("A(x)+B(x)=\n");
    while(a!=NULL & b!=NULL) {
        if (b->inx < a->inx) {
            printf("(%.2lf)*x^(%.2lf)+",a->cof,a->inx);
            a = a->pnode;
        } else if(b->inx > a->inx) {
            printf("(%.2lf)*x^(%.2lf)+",b->cof,b->inx);
            b = b->pnode;
        } else {
            printf("(%.2lf)*x^(%.2lf)+",b->cof+a->cof,a->inx);
            a = a->pnode;
            b = b->pnode;
        }
    }
    while (a) {
        printf("(%.2lf)*x^(%.2lf)+",a->cof,a->inx);
        a = a->pnode;
    }
    while (b) {
        printf("(%.2lf)*x^(%.2lf)+",b->cof,b->inx);
        b = b->pnode;
    }
    printf("0\n");
    a = ahead;
    b = bhead;
    printf("A(x)-B(x)=\n");
    while(a!=NULL & b!=NULL) {
        if (b->inx < a->inx) {
            printf("(%.2lf)*x^(%.2lf)+",a->cof,a->inx);
            a = a->pnode;
        } else if(b->inx > a->inx) {
            printf("(%.2lf)*x^(%.2lf)+",-1*b->cof,b->inx);
            b = b->pnode;
        } else {
            printf("(%.2lf)*x^(%.2lf)+",a->cof-b->cof,a->inx);
            a = a->pnode;
            b = b->pnode;
        }
    }
    while (a) {
        printf("(%.2lf)*x^(%.2lf)+",a->cof,a->inx);
        a = a->pnode;
    }
    while (b) {
        printf("(%.2lf)*x^(%.2lf)+",-1*b->cof,b->inx);
        b = b->pnode;
    }
    printf("0\n");
    // NOW FREE THE LINK LIST
    a = ahead;
    b = bhead;
    while (a)
    {
        free(a);
        a = a->pnode;
    }
    while (b)
    {
        free(b);
        b = b->pnode;
    }
    end = clock();
    printf("%lf s total",(double)(end-sta)/CLOCKS_PER_SEC);
    return 0;
}

int assign(pol *need,double cof,double inx,pol *p)
{
    need->pnode = p;
    need->cof = cof;
    need->inx = inx;
    return 0;
}

pol* create_pol(int many)
{
    int i;
    clock_t end,sta,ex_sum=0;
    sta = clock();
    pol *who,*HeadOfWho=NULL;
    for(i=1;i<=many;i++) {
        double cof,inx;
        ex_sum += clock();
        scanf("%lf %lf",&cof,&inx);
        ex_sum -= clock();
        if(!HeadOfWho) {
            who = HeadOfWho = (pol*)malloc(N);
            assign(who,cof,inx,NULL);
        } else {
            if(inx > who->inx) {
                who = (pol*)malloc(N);
                assign(who,cof,inx,HeadOfWho);
                HeadOfWho = who;
            } else {
                pol *ww;
                while (inx < who->inx) {
                    ww = who;
                    who = who->pnode;
                    if(!who) {
                        who = (pol*)malloc(N);
                        assign(who,cof,inx,NULL);
                        ww->pnode = who;
                    }
                }
                if(inx > who->inx) {
                    pol *dd = (pol*)malloc(N);
                    assign(dd,cof,inx,who);
                    ww->pnode = dd;
                } else if(inx == who->inx) {
                    who->cof += cof;
                }
            }
        }
        who = HeadOfWho;
    }
    end = clock();
    printf("%lf s total create link_list\n",(double)(end-sta+ex_sum)/CLOCKS_PER_SEC);
    return who;
}