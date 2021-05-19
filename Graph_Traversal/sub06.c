/* 
图的遍历
1.用邻接表方式存储
2.输入一个图，构建其邻接表的存储
3.进行图的深度优先遍历及广度优先遍历
//拓展
1.用邻接矩阵实现，程序有哪些不同
2.用图的遍历算法实现解决迷宫问题的最短路径
  如果不存在路径，则进行提示
*/

/*
从某一始点出发，其在图中遍历的序列一定处于以该始点为根的生成树上
（无向图为连通分量）（有向图为强连通分量）
故从该始点到该点，必定存在一条路径
迷宫的最短路径：
1、Dijkstra算法
2、弗洛伊德算法
*/

/*
使用邻接矩阵进行求解（以无向图为例）
深度优先遍历实际上仍然是寻找与当前结点关联的结点
广度优先遍历也是寻找当前结点所有与之关联的结点 
*/

/*
[2021.5.18]出现问题，需要重新规划
使用图的遍历算法求解迷宫问题的最短路径
在保持图的遍历的同时，多添加一个操作
即要遍历所有边，即忽视已经访问过，对结点的最短路径进行计算
可以另加一个最短路径辅助结构，存储每个结点的运算过程最短路径长度值
规定迷宫中每个结点的最短路径初值为超过最大值，始点最短路径为0（迷宫开始点）
若遍历结束后终点路径值仍未0，则认为迷宫不通（或者看访问数组中是否为0）
[2021.5.19]重新规划：思想来源自https://www.cnblogs.com/lxt1105/p/6440030.html
即记录遍历的过程，对每条遍历路径记录其遍历的结点以及其顺序
访问数组意义变成当前路径已经访问过，而不是全局已经访问过
使用path[]记录路径，其结构相当为栈，每次记录的结点存入栈中
同时设置length，记录当前到终点的最短路径值
即遍历改成遍历每个路径，visited意为记录当前路径（已访问过不要再走）
*若是记录始点到所有结点的最短路径，可以把path设为二维数组，即一个记录便是对应节点的最短路径
*方法和记录单个结点一样
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//宏定义常量
#define MAX_SIZE 200
#define ASI_ADJ (at*)malloc(sizeof(at))

//构建邻接表数据结构
typedef struct adjvertex at;
struct adjvertex
{	
	int position;
	at *next;
};
typedef struct vertex vt;
struct vertex
{
	int value;
	at *link;	
};

//定义全局变量
vt node_list[MAX_SIZE];
int IS_NODE_DONE[MAX_SIZE] = {0}; //辅助数组表示是否已经访问过，0未访问过，1访问过
int queue[MAX_SIZE]; //广度优先遍历使用队列进行辅助
int queue_head = 0,queue_tail = -1;
int node_matrix[MAX_SIZE][MAX_SIZE] = {0}; //邻接矩阵
int path[MAX_SIZE] = {0}; //递归路径(当前)
int path_top = -1; //递归路径（当前）栈顶部指针
int min_path[MAX_SIZE] = {0}; //最短路径
int min_path_top = -1; //最短路径栈栈顶指针
int length; //记录最短路径值

int initial(int node_account)
{
	//初始化访问数组
	for(;node_account>=1;node_account--)
	{
		IS_NODE_DONE[node_account-1] = 0;
	}
	return 0;
}

int DFS(int position)
{
	//图的深度优先遍历
	at *P;
	P = node_list[position].link;
	while (P!=NULL)
	{
		if(IS_NODE_DONE[P->position]==0)
		{
			printf("%d ",node_list[P->position].value);
			IS_NODE_DONE[P->position] = 1;
			DFS(P->position);
		}
		P = P->next;
	}
	return 0;
}

int DFS_MATRIX(int position,int node_account)
{
	//使用邻接矩阵对图进行深度优先遍历
	int P;
	P = 0;
	for(;P<node_account;P++)
	{
		if(node_matrix[position][P] == 1)
		{
			if(IS_NODE_DONE[P] == 0)
			{
				printf("%d ",node_list[P].value);
				IS_NODE_DONE[P] = 1;
				DFS_MATRIX(P,node_account);
			}
		}
	}
	return 0;
}

int DFS_FIND_MIN_ROAD(int position,int des,int curr_length)
{
	//使用深度优先遍历查找始点到终点的最短路径
	//先访问，再进行递归
	at *P;
	int temp;
	P = node_list[position].link;
	//及访问到的路径正好为终点时
	if(position == des)
	{
		if(curr_length <= length)
		{
			if(curr_length < length)
			{
				min_path_top = -1;
			}
			else
			{
				min_path[++min_path_top] = -1; //第一条和第二条最短路径的分割线
			}
			for(temp=path_top;temp>=0;temp--)
			{
				min_path[++min_path_top] = path[temp];
			}
			//当前最短路径小于已经记录的最短路径
			length = curr_length;
		}
	}
	while (P!=NULL)
	{
		if(IS_NODE_DONE[P->position] == 0)
		{
			IS_NODE_DONE[P->position] = 1;
			path[++path_top] = P->position;
			DFS_FIND_MIN_ROAD(P->position,des,curr_length+1);
			path_top--;
			IS_NODE_DONE[P->position] = 0;
		}
		P = P->next;
	}
	return 0;
}

int main(void)
{
	int tempa,tempb; //临时变量
	int node_account,line_account;
	//初始化
	for(tempb=1;tempb<=MAX_SIZE;tempb++)
	{
		node_list[tempb-1].link = NULL;
	}
	//数据录入
	printf("PLZ insert how many nodes of the graph\n");
	scanf("%d",&node_account);
	printf("Now PLZ insert the node value\n"
		   "The id will be automatically assigned\n");
	for(tempa=1;tempa<=node_account;tempa++)
	{
		scanf("%d",&node_list[tempa-1].value);
	}
	printf("Now print the list with the ID\n");
	//输出邻接表，带编号
	printf("%5s%6s\n","ID","VALUE");
	for(tempa=1;tempa<=node_account;tempa++)
	{
		printf("%5d%5d\n",tempa-1,node_list[tempa-1].value);
	}
	//录入边
	printf("How many lines?\n");
	scanf("%d",&line_account);
	printf("Now PLZ insert the line\n"
		   "The format is <a,b>\n"
		   "a b stands for the id in the list\n");
	for(tempa=1;tempa<=line_account;tempa++)
	{
		int ida,idb;
		getchar();
		scanf("(%d,%d)",&ida,&idb);
		at *new_adj_a = ASI_ADJ;
		at *new_adj_b = ASI_ADJ;
		new_adj_a->position = idb;
		new_adj_a->next = node_list[ida].link;
		node_list[ida].link = new_adj_a;
		new_adj_b->position = ida;
		new_adj_b->next = node_list[idb].link;
		node_list[idb].link = new_adj_b;
		//构建邻接矩阵
		node_matrix[ida][idb] = 1;
		node_matrix[idb][ida] = 1;
	}
	//开始图的深度优先遍历
	printf("NOW DFS\n");
	for(tempa=1;tempa<=node_account;tempa++)
	{
		if(IS_NODE_DONE[tempa-1]==0)
		{
			printf("%d ",node_list[tempa-1].value);
			IS_NODE_DONE[tempa-1] = 1;
			DFS(tempa-1);
			printf("\n");
		}
	}
	//开始图的广度优先遍历
	//先访问，再入队列
	//初始化访问数组
	initial(node_account);
	//开始遍历
	printf("NOW BFS\n");
	for(tempa=1;tempa<=node_account;tempa++)
	{
		if(IS_NODE_DONE[tempa-1] == 0)
		{
			queue_tail = queue_head;
			printf("%d ",node_list[tempa-1].value);
			IS_NODE_DONE[tempa-1] = 1;
			queue[queue_head] = tempa-1; //初始点入列,以ID入列
			while (queue_head<=queue_tail)
			{
				at *P;
				P = node_list[queue[queue_head]].link;	
				while (P!=NULL)
				{
					if(IS_NODE_DONE[P->position] == 0)
					{
						printf("%d ",node_list[P->position].value);
						IS_NODE_DONE[P->position] = 1;
						queue[++queue_tail] = P->position;
					}
					P = P->next;
				}
				queue_head++;
			}
			printf("\n");		
		}
	}
	//使用邻接矩阵对图进行深度优先遍历
	printf("NOW DFS_MARTIX\n");
	initial(node_account);
	for(tempa=1;tempa<=node_account;tempa++)
	{
		if(IS_NODE_DONE[tempa-1] == 0)
		{
			printf("%d ",node_list[tempa-1].value);
			IS_NODE_DONE[tempa-1] = 1;
			DFS_MATRIX(tempa-1,node_account);
			printf("\n");
		}
	}
	//使用邻接矩阵对图进行广度优先遍历
	//先访问，再入列
	printf("NOW BFS_MARTIX\n");
	initial(node_account);
	//初始化队列
	queue_head = 0;queue_tail = -1;
	for(tempa=1;tempa<=node_account;tempa++)
	{
		if(IS_NODE_DONE[tempa-1] == 0)
		{
			queue_tail = queue_head;
			printf("%d ",node_list[tempa-1].value);
			IS_NODE_DONE[tempa-1] = 1;
			queue[queue_head] = tempa-1;
			while (queue_head<=queue_tail)
			{
				int position = queue[queue_head];
				int P=0;
				for(;P<node_account;P++)
				{
					if(node_matrix[position][P] == 1)
					{
						if(IS_NODE_DONE[P] == 0)
						{
							printf("%d ",node_list[P].value);
							IS_NODE_DONE[P] = 1;
							queue[++queue_tail] = P;
						}
					}
				}
				queue_head++;
			}
			printf("\n");
		}
	}
	//[2021.5.18]出现问题，需要重新规划算法
	//使用邻接表，进行深度遍历，同时指定终点和始点
	//输出始点到终点的最短路径值以及路径
	//若有多个符合条件的路径，则全部输出
	int stf,destination;
	initial(node_account);
	printf("PLZ insert two IDs stands for the stf and destination\n");
	scanf("%d %d",&stf,&destination);
	//开始运算
	length = MAX_SIZE + 1;
	printf("NOW LOADING......\n");
	path[++path_top] = stf;
	IS_NODE_DONE[stf] = 1;
	DFS_FIND_MIN_ROAD(stf,destination,0);
	path_top--;
	IS_NODE_DONE[stf] = 0;
	if(length != MAX_SIZE+1)
	{
		printf("The minmum road is\n");
		for(tempa=min_path_top;tempa>=0;tempa--)
		{
			if(min_path[tempa] == -1)
			{
				printf("\n");
			}
			else
			{
				printf("%d ",node_list[min_path[tempa]].value);
			}
		}
		printf("\n");
		printf("The minmum length of roads of %d to %d is %d\n",
			node_list[stf].value,node_list[destination].value,length);
	}
	else
	{
		printf("NOT FIND!\n");
	}
	return 0;
}