//对链表的结构进行修改
//以便更好进行乘除法、加减法运算
//循环带表头结点链表

#include <stdio.h>
#include <stdlib.h>

typedef struct list ll;
struct list
{
    double cof;
    double inx;
    ll *next;
};

#define N sizeof(ll)

ll *A,*AH,*B,*BH;

//复制多项式
ll *copy(ll *a,ll *ah);
//将多项式中cof为0的项剔除
ll *del_ill(ll *a,ll *ah);
//创建多项式链表
ll *create_list(int amo);
//多项式相加操作，从头节点next开始
ll *add(ll *a,ll *b,ll *ah,ll *bh);
//多项式相减操作，从头节点next开始
ll *dec(ll *a,ll *b,ll *ah,ll *bh);
//多项式相乘操作，从头节点next开始
ll *mul(ll *a,ll *b,ll *ah,ll *bh);
//多项式相除操作，从头节点next开始
ll **divb(ll *a,ll *b,ll *ah,ll *bh);

int main(void)
{
    int AmoA,AmoB;
    printf("Plz input the amounts of A and B\n");
    scanf("%d %d",&AmoA,&AmoB);
    AH = create_list(AmoA);
    BH = create_list(AmoB);
    ll *addition,*decrease,*addH,*decH;
    addH = addition = add(AH->next,BH->next,AH,BH);
    decH = decrease = dec(AH->next,BH->next,AH,BH);
    addH = del_ill(addH->next,addH);
    decH = del_ill(decH->next,decH);
    addition = addH->next;
    decrease = decH->next;
    printf("A(x)+B(x)=\n");
    while (addition!=addH)
    {
        printf("(%.1lf)x^(%.1lf)+",addition->cof,addition->inx);
        addition = addition->next;
    }
    printf("0\nA(x)-B(x)=\n");
    while (decrease!=decH)
    {
        printf("(%.1lf)x^(%.1lf)+",decrease->cof,decrease->inx);
        decrease = decrease->next;
    }
    printf("0\nA(x)*B(x)=\n");
    ll *multi,*mulH;
    ll **cai;
    ll *cofOfdiv,*inxOfdiv,*chOfdiv,*ihOfdiv;
    multi = mulH = mul(AH->next,BH->next,AH,BH);
    cai = divb(AH->next,BH->next,AH,BH);
    mulH = del_ill(mulH->next,mulH);
    multi = mulH->next;
    chOfdiv = cai[0];
    ihOfdiv = cai[1];
    cofOfdiv = chOfdiv->next;
    inxOfdiv = ihOfdiv->next;
    A = AH->next;
    B = BH->next;
    while (multi!=mulH)
    {
        printf("(%.1lf)x^(%.1lf)+",multi->cof,multi->inx);
        multi = multi->next;
    }
    printf("0\nA(x)/B(x)=\n");
    while (A!=AH)
    {
        printf("(%.1lf)x^(%.1lf)+",A->cof,A->inx);
        A = A->next;
    }
    printf("0 = [");
    while (cofOfdiv!=chOfdiv)
    {
        printf("(%.1lf)x^(%.1lf)+",cofOfdiv->cof,cofOfdiv->inx);
        cofOfdiv = cofOfdiv->next;
    }
    printf("0]*[");
    while (B!=BH)
    {
        printf("(%.1lf)x^(%.1lf)+",B->cof,B->inx);
        B = B->next;
    }
    printf("0]+[");
    while (inxOfdiv!=ihOfdiv)
    {
        printf("(%.1lf)x^(%.1lf)+",inxOfdiv->cof,inxOfdiv->inx);
        inxOfdiv = inxOfdiv->next;
    }
    printf("0]\n");
    return 0;
}

ll *copy(ll *a,ll *ah)
{
    ll *H,*S;
    H = S = (ll*)malloc(N);
    H->next = H;
    while (a!=ah)
    {
        S->next = (ll*)malloc(N);
        S = S->next;
        S->cof = a->cof;
        S->inx = a->inx;
        S->next = H;
        a = a->next;
    }
    return H;
}

ll *del_ill(ll *a,ll *ah)
{
    ll *pre=ah;
    while (a!=ah)
    {
        if(a->cof==0)
        {
            pre->next = a->next;
            free(a);
            a = pre;
        }
        pre = a;
        a = a->next;
    }
    return ah;
}

ll *create_list(int amo)
{
    int i=1;
    ll *H,*S;
    H = S = (ll*)malloc(N);
    H->next = H;
    for(;i<=amo;i++)
    {
        ll *pre;
        double inx,cof;
        scanf("%lf %lf",&cof,&inx);
        pre = H;S = H->next;H->inx = inx;
        while (inx < S->inx)
        {
            pre = S;
            S = S->next;
        }
        if(inx == S->inx && S!=H)
        {
            S->cof += cof;
        } else {
            //插入操作
            ll *nw;
            nw = (ll*)malloc(N);
            nw->inx = inx;
            nw->cof = cof;
            nw->next = S;
            pre->next = nw;
        }
    }
    H->inx = 0;
    return H;
}

ll *add(ll *a,ll *b,ll *ah,ll *bh)
{
    ll *H,*S;
    H = S = (ll*)malloc(N);
    H->next = H;
    while(a!=ah && b!=bh)
    {
        S->next = (ll*)malloc(N);
        S = S->next;
        S->next = H;
        if(a->inx > b->inx)
        {
            S->cof = a->cof;
            S->inx = a->inx;
            a = a->next;
        }
        else if(a->inx < b->inx)
        {
            S->cof = b->cof;
            S->inx = b->inx;
            b = b->next;
        }
        else
        {
            S->cof = a->cof+b->cof;
            S->inx = a->inx;
            a = a->next;
            b = b->next;
        }
    }
    while(a!=ah)
    {
        S->next = (ll*)malloc(N);
        S = S->next;
        S->next = H;
        S->cof = a->cof;
        S->inx = a->inx;
        a = a->next;
    }
    while(b!=bh)
    {
        S->next = (ll*)malloc(N);
        S = S->next;
        S->next = H;
        S->cof = b->cof;
        S->inx = b->inx;
        b = b->next;
    }
    return H;
}

ll *dec(ll *a,ll *b,ll *ah,ll *bh)
{
    ll *H,*S;
    H = S = (ll*)malloc(N);
    H->next = H;
    while(a!=ah && b!=bh)
    {
        S->next = (ll*)malloc(N);
        S = S->next;
        S->next = H;
        if(a->inx > b->inx)
        {
            S->cof = a->cof;
            S->inx = a->inx;
            a = a->next;
        }
        else if(a->inx < b->inx)
        {
            S->cof = -1*b->cof;
            S->inx = b->inx;
            b = b->next;
        }
        else
        {
            S->cof = a->cof-b->cof;
            S->inx = a->inx;
            a = a->next;
            b = b->next;
        }
    }
    while(a!=ah)
    {
        S->next = (ll*)malloc(N);
        S = S->next;
        S->next = H;
        S->cof = a->cof;
        S->inx = a->inx;
        a = a->next;
    }
    while(b!=bh)
    {
        S->next = (ll*)malloc(N);
        S = S->next;
        S->next = H;
        S->cof = -1*b->cof;
        S->inx = b->inx;
        b = b->next;
    }
    return H;
}

ll *mul(ll *a,ll *b,ll *ah,ll *bh)
{
    ll *H,*S;
    H = S = (ll*)malloc(N);
    H->next = H;
    while (a!=ah)
    {
        while (b!=bh)
        {
            ll *pre;
            double cof = a->cof*b->cof;
            double inx = a->inx+b->inx;
            pre = H;S = H->next;H->inx = inx;
            while (inx < S->inx)
            {
                pre = S;
                S = S->next;
            }
            if(inx == S->inx && S!=H)
            {
                S->cof += cof;
            } else {
                //插入操作
                ll *nw;
                nw = (ll*)malloc(N);
                nw->inx = inx;
                nw->cof = cof;
                nw->next = S;
                pre->next = nw;
            }
            b = b->next;
        }
        a = a->next;
        b = bh->next;
    }
    return H;   
}

ll **divb(ll *a,ll *b,ll *ah,ll *bh)
{
    ll *Mx,*tempx;
    ll *NxH,*MxH,*tempH,*subH;
    Mx = MxH = (ll*)malloc(N);
    MxH->next = MxH;
    tempH = (ll*)malloc(N);
    tempH->next = (ll*)malloc(N);
    tempx = tempH->next;
    tempx->next = tempH;
    NxH = copy(ah->next,ah);
    NxH = del_ill(NxH->next,NxH);
    while (NxH->next->inx >= b->inx && NxH->next!=NxH)
    {
        double co1,in1;
        co1 = NxH->next->cof/b->cof;
        in1 = NxH->next->inx-b->inx;
        Mx->next = (ll*)malloc(N);
        Mx = Mx->next;
        Mx->cof = co1;
        Mx->inx = in1;
        Mx->next = MxH;
        tempx->cof = co1;
        tempx->inx = in1;
        subH = mul(tempH->next,bh->next,tempH,bh);
        NxH = dec(NxH->next,subH->next,NxH,subH);
        NxH = del_ill(NxH->next,NxH);
    }
    ll **CAI;
    CAI = (ll**)malloc(2*sizeof(ll**));
    CAI[0]=MxH;
    CAI[1]=NxH;
    return CAI;
}