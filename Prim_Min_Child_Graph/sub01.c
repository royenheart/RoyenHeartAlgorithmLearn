/* Prim算法生成最小生成树 */
/* 使用带权邻接矩阵 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_VALUE 999

typedef struct lowcost
{
    int from;
    int lowest_value;
}lwc;

int graph[MAX_SIZE][MAX_SIZE];

int main(void)
{
    lwc node_lowcost[MAX_SIZE];
    int tempa,tempb;
    int node_account,line_account;
    printf("PLZ input the amounts of nodes and lines\n");
    scanf("%d %d",&node_account,&line_account);
    //初始化
    for(tempa=1;tempa<=node_account;tempa++)
    {
        for(tempb=1;tempb<=node_account;tempb++)
        {
            graph[tempa-1][tempb-1] = MAX_VALUE;
        }
        node_lowcost[tempa-1].from = -1;
        node_lowcost[tempa-1].lowest_value = MAX_VALUE;
    }
    printf("PLZ input lines with format <vertexa,vertexb,length>\n"
           "A line occupies a line in terminal\n");
    for(tempa=1;tempa<=line_account;tempa++)
    {
        int va,vb,value;
        fflush(stdin);
        scanf("<%d,%d,%d>",&va,&vb,&value);
        graph[va][vb] = value;
        graph[vb][va] = value;
    }
    //添加辅助数组结构表示每一个结点到当前生成树集合的最短路径：
    //最短路径由关联结点a，关联结点b，权值唯一确定
    //因此存储最短边的另一个关联结点以及对应边的权值
    //长度为0表示已经加入生成树集合（同时由于求最小值可以不在更改）
    //选择初始节点，加入生成树集合之中
    //（循环）更新所有结点的到生成集合的最短边
    //从剩下的结点的最短边中选取整体的最短边，并以K代表对应结点
    //将K代表的（在辅助数组结构中存储）的最短边输出
    //当全部结点已加入生成树中时，算法结束
    printf("PLZ input the start with its id\n");
    int K;
    scanf("%d",&tempa);
    node_lowcost[tempa].lowest_value = 0;
    K = tempa;
    for(tempa=1;tempa<=node_account-1;tempa++)
    {
        int min_length = MAX_VALUE;
        //生成树集合更新后以加入的结点为一边结点重新计算所有结点到生成树集合的最短路径
        for(tempb=1;tempb<=node_account;tempb++)
        {
            if(graph[K][tempb-1] < node_lowcost[tempb-1].lowest_value)
            {
                node_lowcost[tempb-1].lowest_value = graph[K][tempb-1];
                node_lowcost[tempb-1].from = K;
            }
        }
        //更新完毕后从剩下的结点中选择最短路径最短的位置
        for(tempb=1;tempb<=node_account;tempb++)
        {
            int length = node_lowcost[tempb-1].lowest_value;
            if(length!=0 && length < min_length)
            {
                min_length = length;
                K = tempb-1;
            }
        }
        //访问该最短路径（输出）
        printf("<%d,%d> with length %d\n",node_lowcost[K].from,K,node_lowcost[K].lowest_value);
        //将最短路径结点加入生成树集合（原先图中去除，取0代表已被去除）
        node_lowcost[K].lowest_value = 0;
    }
    return 0;
}