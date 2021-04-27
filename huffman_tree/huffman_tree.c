#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct tree TREE;
struct tree
{
    double value;
    char code[MAX_SIZE];
    TREE *lson;
    TREE *rson;
};
typedef struct huff_line hf;
struct huff_line
{
    double value;
    int pos;
};

#define ASI_TREE (TREE*)malloc(sizeof(TREE))

int DNN(TREE *root_ct)
{
    // 前序遍历 递归过程
    if(root_ct != NULL)
    {
        printf("%.2lf ",root_ct->value);
        DNN(root_ct->lson);
        DNN(root_ct->rson);
    }
    return 0;
}

int DNN_CODE(TREE *root_ct,char *fcode)
{
    // 前序遍历 递归过程 建立节点的哈夫曼编码
    if(root_ct != NULL)
    {
        char left[MAX_SIZE]={0},right[MAX_SIZE]={0};
        strcat(root_ct->code,fcode);
        // 当为叶子节点时输出
        if(root_ct->lson==NULL)
        {
            printf("%.2lf:%s\n",root_ct->value,root_ct->code);
        }
        strcat(left,root_ct->code);
        strcat(left,"0");
        strcat(right,root_ct->code);
        strcat(right,"1");
        DNN_CODE(root_ct->lson,left);
        DNN_CODE(root_ct->rson,right);
    }
    return 0;
}

int hfsort(hf *obj,int top)
{
    int t1,t2;
    for(t1=0;t1<top;t1++)
    {
        double min = (obj+t1)->value;
        int pos = t1;
        for(t2=t1+1;t2<=top;t2++)
        {
            if((obj+t2)->value < min)
            {
                min = (obj+t2)->value;
                pos = t2;
            }
        }
        double value;
        int hfpos;
        // 进行交换
        value = (obj+pos)->value;
        hfpos = (obj+pos)->pos;
        (obj+pos)->value = (obj+t1)->value;
        (obj+pos)->pos = (obj+t1)->pos;
        (obj+t1)->value = value;
        (obj+t1)->pos = hfpos;
    }
    return 0;
}

int main(void)
{
    int amounts,top;
    int temp;
    TREE *Rnode[MAX_SIZE];
    hf Aline[MAX_SIZE];
    printf("PLZ input a number which means the amounts of data of root\n");
    scanf("%d",&amounts);
    printf("Input values\n");
    top = amounts-1;
    for(temp=0;temp<=top;temp++)
    {
        double value;
        scanf("%lf",&value);
        Rnode[temp] = ASI_TREE;
        Rnode[temp]->value = value;
        Rnode[temp]->lson = NULL;
        Rnode[temp]->rson = NULL;
        memset(Rnode[temp]->code,0,MAX_SIZE);
        Aline[temp].value = value;
        Aline[temp].pos = temp;
        
    }
    temp = 0;
    while (top-temp>=1)
    {
        temp++;
        amounts++;
        hfsort(Aline,top-temp+1);
        hf add_root;
        add_root.value = Aline[0].value + Aline[1].value;
        Rnode[top+temp] = ASI_TREE;
        Rnode[top+temp]->value = add_root.value;
        // 较小数作为左子树，较大数作为右子树
        int left,right;
        left = (Aline[0].pos<=Aline[1].pos)?Aline[0].pos:Aline[1].pos;
        right = Aline[0].pos + Aline[1].pos - left;
        Rnode[top+temp]->lson = Rnode[left];
        Rnode[top+temp]->rson = Rnode[right];
        memset(Rnode[top+temp]->code,0,MAX_SIZE);
        add_root.pos = top+temp;
        Aline[0] = add_root;
        Aline[1] = Aline[top-temp+1];
    }
    TREE *head = Rnode[Aline[0].pos];
    DNN(head);
    // 对每个节点对应的哈夫曼编码进行求值并输出
    printf("\n");
    DNN_CODE(head,"");
    // 根据哈夫曼树对哈夫曼编码进行解码
    char cry_message[MAX_SIZE]={0};
    getchar();
    gets(cry_message);
    temp = 0;
    TREE *P = head; // 授权P节点访问哈夫曼树
    while (cry_message[temp]!='\0')
    {
        if(P->lson == NULL)
        {
            printf("%.2lf ",P->value);
            P = head;
            temp--;
        }
        else if(cry_message[temp]=='0')
        {
            P = P->lson;
        }
        else
        {
            P = P->rson;
        }
        temp++;
    }
    if(P->lson == NULL)
    {
        printf("%.2lf ",P->value);
    }
    // 释放空间
    top = amounts-1;
    for(temp=0;temp<=top;temp++)
    {
        free(Rnode[temp]);
    }   
    return 0;   
}