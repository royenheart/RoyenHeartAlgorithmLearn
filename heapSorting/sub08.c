/*
    HEAP SORTING
    堆排序
    操作：
    1、由无序序列生成一个堆
    2、由堆生成一个有序序列
    筛选：生成堆和生成有序序列的重要过程
    堆顶至叶子的调整过程：筛选
    因为堆的结构是完全二叉树，且对一个三角关系，父节点值都大于（小于）其左右孩子结点的值
    故要从堆顶开始调整。
    无序序列到堆：
        从非终端结点开始（终端节点没有左右子树，没有意义调整）
        对父节点的访问操作为调整位置
    堆到有序序列：
        从根节点开始，数组存储结构中表示为第一个元素
        因为根节点必为整个堆的最小（最大）元素
        对父节点的访问操作为输出，不再放进堆内
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

int exchange(int *a,int *b)
{
    int bucket;
    bucket = *a;
    *a = *b;
    *b = bucket;
    return 0;
}

int main(void)
{
    int heap[MAX_SIZE] = {0};
    int stack[MAX_SIZE] = {0};
    int stack_top = -1;
    int node_account;
    int temp;
    //使用的定理：完全二叉树中第i个结点，其左右孩子的编号分别为2*i和2*i+1
    //这里使用最小堆，即根节点为整个序列中值最小的元素
    printf("PLZ input the number of your nodes\n");
    scanf("%d",&node_account);
    printf("PLZ input the value of every node\n");
    for(temp=0;temp<node_account;temp++)
    {
        scanf("%d",&heap[temp]);
    }
    //开始由无序序列转换至堆
    for(temp=node_account/2-1;temp>=0;temp--)
    {
        //开始递归调整
        //1：调整父节点-转移位置
        //2：对转移位置后的根节点判断是否仍然需要调整
        //3：若仍然需要调整则重复1和2步骤
        int father = temp;
        while (father <= node_account/2-1 && (heap[father] > heap[father*2] || heap[father] > heap[father*2+1]))
        {
            if(heap[father*2] < heap[father*2+1])
            {
                exchange(&heap[father*2],&heap[father]);
                father = father*2;
            }
            else
            {
                exchange(&heap[father*2+1],&heap[father]);
                father = father*2+1;
            }
        }
    }
    //开始由堆输出有序序列
    printf("NOW PRINT THE LIST\n");
    for(temp=0;temp<node_account;temp++)
    {
        //先输出根节点,保存至栈中
        //由最后一个结点替代第一个结点
        //以第一个结点为父节点进行筛选，重新使最小元素
        //至堆顶且不破坏堆的结构
        printf("%d ",heap[0]);
        stack[++stack_top] = heap[0];//已经输出的元素不再计入堆中
        heap[0] = heap[node_account-temp-1];
        int father = 0;
        while (father <= (node_account-temp-1)/2-1 && (heap[father] > heap[father*2] || heap[father] > heap[father*2+1]))
        {
            if(heap[father*2] < heap[father*2+1])
            {
                exchange(&heap[father*2],&heap[father]);
                father = father*2;
            }
            else
            {
                exchange(&heap[father*2+1],&heap[father]);
                father = father*2+1;
            }
        }
    }
    printf("\nNOW PRINT THE REVERSE LIST\n");
    while (stack_top>=0)
    {
        printf("%d ",stack[stack_top]);
        stack_top--;
    }
    return 0;
}