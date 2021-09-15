/* 
二叉树
前序、后序、中序遍历
递归方法、非递归方法
层序遍历，计算树的高度
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct tree tree;
struct tree
{
    char value;
    int deep; // 存储深度
    tree *lnode;
    tree *rnode;
};
typedef struct STACK STACK;
struct STACK
{
    int top;
    tree* Tnode[MAX_SIZE];
    int IS_PUT[MAX_SIZE]; // 后序遍历 是否进行访问
};
typedef struct LAYER LAYER;
struct LAYER
{
    tree *node;
    LAYER *next;
};

LAYER *layer[MAX_SIZE]; // 层序遍历 0下标表示第一层 为带表头的单向链表
tree *inode[MAX_SIZE]; 
tree *NULL_TREE;
int top_node = -1;
int top_layer = -1;
STACK Tstack;

#define ASI_LAYER (LAYER*)malloc(sizeof(LAYER))
#define PLUS '+'
#define MINU '-'
#define MULT '*'
#define DIVI '/'

int calculate(int a,int b,char opter)
{
    if(opter == PLUS)
    {
        return a+b;
    }
    else if(opter == MINU)
    {
        return a-b;
    }
    else if(opter == MULT)
    {
        return a*b;
    }
    else if(opter == DIVI)
    {
        if(b == 0)
        {
            FREE_ALL();
            exit(1);
        }
        else
        {
            return a/b;
        }
    }
    else if(a == ':'-48)
    {
        return opter-48;
    }
}

int FREE_ALL(void)
{
    int pos;
    LAYER *Lynode;
    // 释放树空间
    while (top_node>=0)
    {
        free(inode[top_node]);
        top_node--;
    }
    // 释放层序遍历表空间
    for(pos=0;pos<top_layer;pos++)
    {
        Lynode = layer[pos];
        while (Lynode!=NULL)
        {
            free(Lynode);
            Lynode = Lynode->next;
        }    
    }
    return 1;
}

tree *ASI_TREE(void)
{
    top_node++;
    inode[top_node] = (tree*)malloc(sizeof(tree));
    return inode[top_node];
}

tree *create_tree_DNN(tree *root_ct)
{
    // 根据前序遍历建立树
    char value;
    scanf("%c;",&value);
    if(value != ':')
    {   
        root_ct->lnode = ASI_TREE();
        root_ct->rnode = ASI_TREE();
        root_ct->lnode->deep = root_ct->deep + 1;
        root_ct->rnode->deep = root_ct->deep + 1;
        create_tree_DNN(root_ct->lnode);
        create_tree_DNN(root_ct->rnode);
    }
    root_ct->value = value; 
    return root_ct;
}

int DNN(tree *root_ct)
{
    // 前序遍历 递归过程
    if(root_ct->value != ':')
    {
        printf("%c ",root_ct->value);
        DNN(root_ct->lnode);
        DNN(root_ct->rnode);
    }
    return 0;
}

int NDN(tree *root_ct)
{
    // 中序遍历 递归过程
    if(root_ct->value != ':')
    {
        NDN(root_ct->lnode);
        printf("%c ",root_ct->value);
        NDN(root_ct->rnode);
    }
    return 0;
}

int NDN_CAL(tree *root_ct)
{
    // 使用中序遍历的递归过程实现算术表达式的计算
    if(root_ct->value != ':')
    {
        int OPNUM1,OPNUM2;
        char OPTER;
        OPNUM1 = NDN_CAL(root_ct->lnode) - 48;
        OPTER = root_ct->value;
        OPNUM2 = NDN_CAL(root_ct->rnode) - 48;
        root_ct->value = calculate(OPNUM1,OPNUM2,OPTER) + 48;
    }
    return root_ct->value;
}

int NND(tree *root_ct)
{
    // 后序遍历 递归过程
    if(root_ct->value != ':')
    {
        NND(root_ct->lnode);
        NND(root_ct->rnode);
        printf("%c ",root_ct->value);
    }
    return 0;
}


int DNN_NO_RC(tree *P)
{
    // 前序遍历 非递归过程
    Tstack.top = -1;
    while (Tstack.top != -1 || P->value!=':')
    {
        if(P->value != ':')
        {
            printf("%c ",P->value);
            Tstack.Tnode[++Tstack.top] = P;
            P = P->lnode;
        }
        else
        {
            P = Tstack.Tnode[Tstack.top]->rnode;
            Tstack.top--;
        }
    }
    return 0;
}

int NDN_NO_RC(tree *P)
{
    // 中序遍历 非递归过程
    Tstack.top = -1;
    while (Tstack.top!=-1 || P->value!=':')
    {
        while (P->value!=':')
        {
            Tstack.Tnode[++Tstack.top] = P;
            P = P->lnode;
        }
        if(Tstack.top!=-1)
        {
            printf("%c ",Tstack.Tnode[Tstack.top]->value);
            P = Tstack.Tnode[Tstack.top]->rnode;
            Tstack.top--;
        }
    }
    return 0;
}

int NND_NO_RC(tree *P)
{
    // 后序遍历 非递归过程
    Tstack.top = -1;
    while (Tstack.top!=-1 || P->value != ':')
    {
        while (P->value!=':')
        {
            Tstack.Tnode[++Tstack.top] = P;
            Tstack.IS_PUT[Tstack.top] = 1;
            P = P->lnode;
        }
        if(Tstack.top!=-1 && Tstack.IS_PUT[Tstack.top] == 1)
        {
            P = Tstack.Tnode[Tstack.top]->rnode;
            Tstack.IS_PUT[Tstack.top] = 2;
        }
        else
        {
            while (Tstack.top!=-1 && Tstack.IS_PUT[Tstack.top] == 2)
            {
                printf("%c ",Tstack.Tnode[Tstack.top]->value);
                Tstack.top--;
            }
            P = NULL_TREE;
        }
    }
}

int LAYER_LS(tree *P)
{
    LAYER *UP_P,*DOWN_P;
    top_layer = 0;
    layer[top_layer] = ASI_LAYER;
    layer[top_layer]->next = NULL;
    if(P->value!=':')
    {
        layer[top_layer]->next = ASI_LAYER;
        layer[top_layer]->next->node = P;
        layer[top_layer]->next->next = NULL;
    }
    do
    {
        top_layer++;
        UP_P = layer[top_layer-1]->next;
        DOWN_P = ASI_LAYER;
        DOWN_P->next = NULL;
        layer[top_layer] = DOWN_P;
        while (UP_P != NULL)
        {
            P = UP_P->node;
            if (P->lnode->value!=':')
            {
                DOWN_P->next = ASI_LAYER;
                DOWN_P = DOWN_P->next;
                DOWN_P->node = P->lnode;
                DOWN_P->next = NULL;
            }
            if(P->rnode->value!=':')
            {
                DOWN_P->next = ASI_LAYER;
                DOWN_P = DOWN_P->next;
                DOWN_P->node = P->rnode;
                DOWN_P->next = NULL;
            }
            UP_P = UP_P->next;
        }
    } while (layer[top_layer]->next!=NULL);
    return 0;
}

int main(void)
{
    // : 表示当前节点为空节点
    // 建立空树
    NULL_TREE = ASI_TREE();
    NULL_TREE->value = ':'; 
    Tstack.top = -1;
    tree *root;
    root = ASI_TREE();
    root->deep = 1;
    root->rnode = NULL;
    root->lnode = NULL;
    printf("PLZ now input the node of the tree\n"
           ": stands for the current node is NULL\n"
           "The format should be A;\n");
    root = create_tree_DNN(root);
    tree *P; 
    P = root; // 授权树根，进行访问
    printf("DNN string:\n");
    DNN(P);printf("\n");
    printf("NDN string:\n");
    NDN(P);printf("\n");
    printf("NND string:\n");
    NND(P);printf("\n");
    printf("DNN_NO_RC\n");
    DNN_NO_RC(P);printf("\n");
    printf("NDN_NO_RC\n");
    NDN_NO_RC(P);printf("\n");
    printf("NND_NO_RC\n");
    NND_NO_RC(P);printf("\n");
    // 建立层序遍历表 进行层序遍历
    printf("LAYER_LS:\n");
    LAYER_LS(P);
    int pos=0;
    LAYER *Lynode;
    for(;pos<top_layer;pos++)
    {
        Lynode = layer[pos]->next;
        while (Lynode!=NULL)
        {
            printf("%c ",Lynode->node->value);
            Lynode = Lynode->next;
        }    
    }
    printf("\n");
    // 统计数的高度
    printf("The height:\n%d\n",top_layer);
    // 根据中序序列（带NULL）实现二叉树的建立
    tree *root_NDN;
    root_NDN = ASI_TREE();
    root_NDN->deep = 1;
    root_NDN->rnode = NULL;
    root_NDN->lnode = NULL;
    // 根据树实现算数表达式的运算
    printf("PLZ now input the node of the tree\n"
           ": stands for the current node is NULL\n"
           "The format should be A;\n");
    getchar();
    root_NDN = create_tree_DNN(root_NDN);
    tree *Q = root_NDN;
    NDN_CAL(Q);
    printf("%d\n",(Q->value-48));
    // 释放空间
    FREE_ALL();
    return 0;   
}