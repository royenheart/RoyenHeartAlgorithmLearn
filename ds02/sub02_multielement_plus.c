//实现多元多项式的加法
#include <stdio.h>
#include <stdlib.h>

typedef struct list_of_whole lw;
typedef struct list_of_one lo;
struct list_of_whole
{
    lo *head;
    lw *next;
};
struct list_of_one
{
    double cof;
    double inx;
    lo *next;
};

#define Nofw sizeof(lw)
#define Nofo sizeof(lo)

lw *AH,*BH,*A,*B;

lw *create(int amo);

int main(void)
{
    int type=-1;
    int amofa,amofb;
    printf("Plz input the paraments of A and B\n");
    scanf("%d %d",&amofa,&amofb);
    printf("A:\n");
    AH = create(amofa);
    printf("B:\n");
    BH = create(amofb);
    A = AH->next;
    B = BH->next;
    lw *CH,*C;
    C = CH = (lw*)malloc(Nofw);
    CH->next = CH;
    while (A!=AH && B!=BH)
    {
        C->next = (lw*)malloc(Nofw);
        C = C->next;
        C->next = CH;
        lo *ch,*c;
        lo *ah,*a,*bh,*b;
        c = ch = (lo*)malloc(Nofo);
        ch->next = ch;
        ah = A->head;
        bh = B->head;
        a = ah->next;
        b = bh->next;
        while (a!=ah && b!=bh)
        {
            c->next = (lo*)malloc(Nofo);
            c = c->next;
            c->next = ch;
            if(a->inx > b->inx)
            {
                c->cof = a->cof;
                c->inx = a->inx;
                a = a->next;
            } 
            else if(a->inx < b->inx) 
            {
                c->cof = b->cof;
                c->inx = b->inx;
                b = b->next;
            }
            else
            {
                c->cof = a->cof+b->cof;
                c->inx = a->inx;
                a = a->next;
                b = b->next; 
            }
        }
        while (a!=ah)
        {
            c->next = (lo*)malloc(Nofo);
            c = c->next;
            c->next = ch;
            c->cof = a->cof;
            c->inx = a->inx;
            a = a->next;
        }
        while (b!=bh)
        {
            c->next = (lo*)malloc(Nofo);
            c = c->next;
            c->next = ch;
            c->cof = b->cof;
            c->inx = b->inx;
            b = b->next;
        }
        C->head = ch;
        A = A->next;
        B = B->next;
    }
    while (A!=AH)
    {
        C->next = (lw*)malloc(Nofw);
        C = C->next;
        C->next = CH;
        lo *ch,*c;
        lo *ah,*a;
        c = ch = (lo*)malloc(Nofo);
        ch->next = ch;
        ah = A->head;
        a = ah->next;
        while (a!=ah)
        {
            c->next = (lo*)malloc(Nofo);
            c = c->next;
            c->next = ch;
            c->cof = a->cof;
            c->inx = a->inx;
            a = a->next;
        }
        C->head = ch;
        A = A->next;
    }
    while (B!=BH)
    {
        C->next = (lw*)malloc(Nofw);
        C = C->next;
        C->next = CH;
        lo *ch,*c;
        lo *bh,*b;
        c = ch = (lo*)malloc(Nofo);
        ch->next = ch;
        bh = B->head;
        b = bh->next;
        while (b!=bh)
        {
            c->next = (lo*)malloc(Nofo);
            c = c->next;
            c->next = ch;
            c->cof = b->cof;
            c->inx = b->inx;
            b = b->next;
        }
        C->head = ch;
        B = B->next;
    }
    //now print the plus of A+B
    printf("A(list)+B(list)=\n");
    C = CH->next;
    while (C!=CH)
    {
        type++;
        lo *h,*p;
        h = C->head;
        p = h->next;
        while (p!=h)
        {
            printf("(%.1lf)*%c^(%.1lf)+",p->cof,65+type,p->inx);
            p = p->next;
        }
        printf("0+\n");
        C = C->next;
    }
    printf("END\n");
    // NOW FREE THE LINK LIST
    A = AH;
    B = BH;
    C = CH;
    while (A!=AH)
    {
        free(A);
        A = A->next;
    }
    while (B!=BH)
    {
        free(B);
        B = B->next;
    }
    while (C!=CH)
    {
        free(C);
        C = C->next;
    }
    free(AH);free(BH);free(CH);
    return 0;
}

lw *create(int amo)
{
    int i=1,j=1;
    lw *H,*S;
    S = H = (lw*)malloc(Nofw);
    H->next = H;
    for(;i<=amo;i++)
    {
        int amount;
        printf("now it's paraments %d,input the amounts of this list\n",i);
        scanf("%d",&amount);
        printf("input the value list\n");
        S->next = (lw*)malloc(Nofw);
        S = S->next;
        S->head = (lo*)malloc(Nofo);
        S->next = H;
        lo *pre,*Ho,*So;
        Ho = S->head;Ho->next = Ho;
        for(j=1;j<=amount;j++)
        {
            double cof,inx;
            scanf("%lf %lf",&cof,&inx);
            pre = Ho;So = Ho->next;Ho->inx = inx;
            while (inx < So->inx)
            {
                pre = So;
                So = So->next;
            }
            if(inx == So->inx && So!=Ho)
            {
                So->cof += cof;
            } 
            else 
            {
                //插入操作
                lo *nw;
                nw = (lo*)malloc(Nofo);
                nw->inx = inx;
                nw->cof = cof;
                nw->next = So;
                pre->next = nw;
            }
        }
    }
    return H;
}