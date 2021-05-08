#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

typedef struct tree TREE;
struct tree
{
    int value;
    int p; 
    // p表示当前节点的平衡因子（左子树深度和右子树深度的差值）
    // 不需要绝对值， 使用 -1，0，-1 能代表是哪一边的子树导致了不平衡
    TREE *lnode;
    TREE *rnode;
};
typedef struct stack STACK;
struct stack
{
    TREE *content[MAX_SIZE];
    int top;
};

STACK inode; // 节点索引栈

TREE *ASI_TREE(void)
{
    inode.top++;
    inode.content[inode.top] = (TREE*)malloc(sizeof(TREE));
    return inode.content[inode.top];
}

int cal_p(TREE* node)
{
    // 计算给定节点的p平衡因子值
    // 规定p平衡因子值等于
    // 左子树深度-右子树深度
    int dep_l,dep_r;
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        dep_l = 1+cal_p(node->lnode);
        dep_r = 1+cal_p(node->rnode);
        node->p = dep_l-dep_r;
        return (dep_l>dep_r)?dep_l:dep_r;
    }
}

int DNN(TREE *root_ct)
{
    // 前序遍历 递归过程
    if(root_ct != NULL)
    {
        printf("%d->%d ",root_ct->value,root_ct->p);
        DNN(root_ct->lnode);
        DNN(root_ct->rnode);
    }
    return 0;
}

int main(void)
{
    int amounts; // 表示有多少个数据量 
    int temp,value; // value记录每次插入的数据
    STACK p_new; // pnode到new_node节点所走过的路径
    p_new.top = 0;
    inode.top = -1;
    TREE *head;
    TREE *root;
    // 根节点初始化
    root = ASI_TREE();
    root->lnode = head;
    root->rnode = head;
    root->p = 0;
    // 表头结点初始化
    head = ASI_TREE();
    head->rnode = root;
    head->lnode = root;
    scanf("%d",&amounts);
    scanf("%d",&value);
    root->value = value;
    for(temp=2;temp<=amounts;temp++)
    {
        TREE *new_node,*fnode,*pnode,*fpnode,*node;
        // new_node: 新插入的节
        // node: 新插入的节点位置（临时）
        // fnode: 新插入的节点的双亲节点
        // pnode: 离插入节点最近的平衡因子为1的节点
        // fpnode: pnode节点的双亲节点
        // 建立新节点
        scanf("%d",&value);
        new_node = ASI_TREE();
        new_node->lnode = NULL;
        new_node->rnode = NULL;
        new_node->p = 0;
        new_node->value = value;
        // 初始化四个节点及栈空间
        p_new.top = -1;
        node = head->lnode;fnode = head;pnode = head->lnode;fpnode = head;
        while (node!=NULL)
        {
            if(node->p != 0)
            {
                pnode = node;
                fpnode = fnode;
                p_new.top = 0;
                p_new.content[p_new.top] = node;
            }
            fnode = node;
            if(new_node->value < node->value)
            {
                node = node->lnode;
            }
            else if(new_node->value > node->value)
            {
                node = node->rnode;
            }
            else
            {
                printf("The same number!\n");
                exit(1);
            }
            if(p_new.top>=0)
            {
                p_new.content[++p_new.top] = node;
            }
        }
        // 插入操作
        p_new.content[++p_new.top] = new_node;
        if(new_node->value < fnode->value)
        {
            fnode->lnode = new_node;
        }
        else
        {
            fnode->rnode = new_node;
        }
        cal_p(head->lnode);
        // 判断pnode为根节点的子树是否失去平衡
        if(abs(pnode->p) > 1)
        {
            // 失去平衡
            // 判断类型--可通过p值的正负进行判断
            // 正数表示左子树出现不平衡，负数表示右子树不平衡
            /*
                转换后每个节点的p平衡因子的值仍需进行计算 
            */
            if(pnode->p*p_new.content[1]->p>0)
            {
                if(fpnode == head)
                {
                    fpnode->lnode = p_new.content[1];
                    fpnode->rnode = p_new.content[1];
                }
                else if(fpnode->lnode == pnode)
                {
                    fpnode->lnode = p_new.content[1];
                }
                else
                {
                    fpnode->rnode = p_new.content[1];
                }
                // ll或者rr不平衡情况
                if(pnode->p > 0)
                {
                    // ll情况
                    pnode->lnode = p_new.content[1]->rnode;
                    p_new.content[1]->rnode = pnode;
                }
                else
                {
                    // rr情况
                    pnode->rnode = p_new.content[1]->lnode;
                    p_new.content[1]->lnode = pnode;
                }
            }
            else
            {
                if(fpnode == head)
                {
                    fpnode->lnode = p_new.content[3];
                    fpnode->rnode = p_new.content[3];
                }
                else if(fpnode->lnode == pnode)
                {
                    fpnode->lnode = p_new.content[3];
                }
                else
                {
                    fpnode->rnode = p_new.content[3];
                }
                if(p_new.content[1]->p<0)
                {
                    // 先左旋
                    p_new.content[1]->rnode = p_new.content[3]->lnode;
                    p_new.content[3]->lnode = p_new.content[1];
                    pnode->lnode = p_new.content[3];
                    pnode->lnode = p_new.content[3]->rnode;
                    p_new.content[3]->rnode = pnode;
                }
                else
                {
                    // 先右旋
                    p_new.content[1]->lnode = p_new.content[3]->rnode;
                    p_new.content[3]->rnode = p_new.content[1];
                    pnode->rnode = p_new.content[3];
                    pnode->rnode = p_new.content[3]->lnode;
                    p_new.content[3]->lnode = pnode;
                }
            }
            // 计算平衡后新的平衡因子
            cal_p(head->lnode);
        }
    }
    // 重新计算平衡因子
    cal_p(head->lnode);
    // 按前序递归遍历输出平衡树
    DNN(head->lnode);
    // 释放空间
    for(temp=0;temp<=inode.top;temp++)
    {
        free(inode.content[temp]);
    }
    return 0;
}