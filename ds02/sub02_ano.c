//STYLE OF INPUT | OUTPUT
//系数：COF
//指数：INX
//STYLE：COF1 INX1 COF2 INX2 ......
//链接结构，以项为数据元素，由：
//数据项：项值，表示指数（一个指数对应一个项）
//数据项：表系数（二级指针，指向每个项对应其所属多项式的系数的地址）
//数据项：指针（双向链表）
//链表内按指数降幂存储（头为最高幂）
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct item ite;
struct item {
    double inx;
    double acof;
    double bcof;
    ite *pnode,*lnode;
};

#define len sizeof(ite)

int create_poly(int many,int type);
int assign(ite* need,int who,double inx,double cof,ite* p,ite* l);
ite* generate_ite(void);

ite *mediav,*head,*tail;

int main(void)
{
    int AmoOfA,AmoOfB;
    clock_t end,sta;
    printf("how many of A\n");
    scanf("%d",&AmoOfA);
    printf("how many of B\n");
    scanf("%d",&AmoOfB);
    create_poly(AmoOfA,1);
    create_poly(AmoOfB,2);
    sta = clock();
    mediav = head;
    printf("A(x)+B(x)=\n");
    while (mediav) {
        printf("(%.2lf)*x^%.2lf+",mediav->acof+mediav->bcof,mediav->inx);
        mediav=mediav->pnode;
    }
    printf("0\n");
    mediav = head;
    printf("A(x)-B(x)=\n");
    while (mediav) {
        printf("(%.2lf)*x^%.2lf+",mediav->acof-mediav->bcof,mediav->inx);
        mediav=mediav->pnode;
    }
    printf("0");
    end = clock();
    printf("\n%lf s total",(double)(end-sta)/CLOCKS_PER_SEC);
    return 0;    
}

int create_poly(int many,int type)
{
    int temb;
    clock_t end,sta,ex_sum=0;
    sta = clock();
    for(temb=1;temb<=many;temb++) {
        double cof,inx;
        ex_sum += clock();
        scanf("%lf %lf",&cof,&inx);
        ex_sum -= clock();
        if(!head) {
            head = tail = mediav = generate_ite();
            assign(head,type,inx,cof,NULL,NULL);
        } else {
            if(inx > head->inx) {
                mediav = generate_ite();
                assign(mediav,type,inx,cof,head,NULL);
                head->lnode = mediav;
                head = mediav;
            } else {
                while(inx < mediav->inx) {
                    ite *tt = mediav;
                    mediav = mediav->pnode;
                    if(!mediav) {
                        mediav = generate_ite();
                        assign(mediav,type,inx,cof,NULL,tt);
                        tt->pnode = mediav;
                        tail = mediav;
                    } 
                }
                if(inx > mediav->inx) {
                    ite *tb = generate_ite();
                    assign(tb,type,inx,cof,mediav,mediav->lnode);
                    mediav->lnode->pnode = tb;
                    mediav->lnode = tb;
                } else if(inx == mediav->inx) {
                    if(type == 1 & !mediav->acof) {
                        mediav->acof = cof;
                    } else if(type == 2 & !mediav->bcof) {
                        mediav->bcof = cof;
                    }
                }
            }
        }
        mediav = head;
    }
    end = clock();
    printf("%lf s total create link_list of %s\n",(double)(end-sta+ex_sum)/CLOCKS_PER_SEC,(type==1)?"A":"B");
    return 0;
}

//1 as A,2 as B 
int assign(ite* need,int who,double inx,double cof,ite* p,ite* l)
{
    need->inx = inx;
    need->lnode = l;
    need->pnode = p;
    if(who == 1) {
        need->acof = cof;
    } else {
        need->bcof = cof;
    }
    return 0;
}

ite* generate_ite(void)
{
    ite* a = (ite*)malloc(len);
    a->acof = 0;
    a->bcof = 0;
    return a;
}