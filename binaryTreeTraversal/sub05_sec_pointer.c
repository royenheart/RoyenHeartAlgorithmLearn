#include <stdio.h>
#include <stdlib.h>

typedef struct tree TREE;
struct tree
{
    char value;
    TREE *lnode;
    TREE *rnode;
};

#define ASI_TREE (TREE*)malloc(sizeof(TREE))

int create_tree(TREE **P)
{
    char value;
    scanf("%c;",&value);
    if(value!=':')
    {
        (*P) = ASI_TREE;
        (*P)->value = value;
        create_tree(&((*P)->lnode));
        create_tree(&((*P)->rnode));
    }
    else
    {
        (*P) = NULL;
    }
    return 0;
}

int DNN(TREE *P)
{
    if(P!=NULL)
    {
        printf("%c ",P->value);
        DNN(P->lnode);
        DNN(P->rnode);
    }
    return 0;
}

int main(void)
{
    TREE *root;
    create_tree(&root);
    DNN(root);
    return 0;
}