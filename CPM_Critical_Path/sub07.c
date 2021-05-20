/*
    关键路径寻找
    拓扑排序，逆拓扑排序
    构建数据结构
    CPMADJ_LIST
    存储入度（index域存储入度以及同时当作
             拓扑排序缓冲区栈以及拟拓扑排序序列栈）
    data部分为结点数据元素类型
    out表示以其为始点的邻接点集合（链表）
    链表数据元素：
    vex域为结点数据元素类型
    dut表示边的权值
    next表示下一个邻接到的结点
    带权有向图
    算法步骤：
    1、初始化入度为0，所有结点的Ve为0（取max值）
    2、计算各节点入度（图的录入同时进行计算）
       *图的录入的同时要为每一个边进行编号
    3、初始使入度为0的结点入拓扑排序缓冲区栈
    4、（循环）当缓冲区栈非空
        -- 退栈，输出缓冲区栈顶元素u(top-1)
        -- 访问栈顶元素所有邻接点K
        -- 访问操作为：
            -- K入度减1
            -- 若K入度为0，入缓冲区栈
            -- 计算Ve(K)，即当Ve(u)+dut<u，k> > 已有Ve(K)值时
               替换
        -- 结束访问后u入逆拓扑排序序列栈
    5、栈空判断：若输出数<结点数（保证给的图是弱连通的），有环，停止运算并报错
    6、初始化，所有结点的Vl设置为Ve[逆拓扑排序区顶部元素]（取min值）
    7、（循环非空）逆拓扑排序栈非空
        -- 退栈 ，输出u（top-1）
        -- 访问栈顶元素u所有后继K
        -- Vl(u) = min{Vl(K)-dut<u,k>}，求出Vl(u)
*/

#include <stdio.h>
#include <stdlib.h>

//声明宏变量
#define MAX_SIZE 200
#define ASI_VE (ve*)malloc(sizeof(ve))

typedef struct line
{
    //边，路径结构
    int line_e; //最早开始时间
    int line_l; //最迟开始时间
    int left; //时间富余量
}li;
typedef struct vertex ve;
struct vertex
{
    int position; //存储对应结点ID
    int dut; //存储路径权值
    ve *next;
    li *in_line;
};
typedef struct CPMADJ_LIST
{
    int index;
    int value;
    ve *link;
}CPMAL;

li road[MAX_SIZE*MAX_SIZE];

int main(void)
{
    CPMAL node_list[MAX_SIZE];
    int temp;
    int top_topo = -1; //拓扑排序栈缓冲区顶部指针
    int top_reverse_topo = -1; //逆拓扑排序栈顶部指针
    int Ve[MAX_SIZE] = {0}; //结点的最早开始时间,以ID为序
    int Vl[MAX_SIZE] = {0}; //结点的最迟开始时间
    int node_account,line_account;
    printf("NOW PLZ input the number of your nodes\n");
    scanf("%d",&node_account);
    printf("NOW PLZ input the value of your nodes\n"
           "The ID will be assigned automatically\n");
    for(temp=0;temp<node_account;temp++)
    {
        //初始化并且录入
        node_list[temp].index = 0;
        node_list[temp].link = NULL;
        scanf("%d",&node_list[temp].value);
    }
    //输出结点对应编号
    printf("%5s%6s\n","ID","VALUE");
	for(temp=0;temp<node_account;temp++)
	{
		printf("%5d%5d\n",temp,node_list[temp].value);
	}
    printf("NOW PLZ input the number of your lines\n");
    scanf("%d",&line_account);
    printf("NOW PLZ input the line\n"
           "The format is <a,b,d>\n"
           "a,b stand for the ID of your chosen node\n"
           "d stands for the dut of your line\n");
    for(temp=0;temp<line_account;temp++)
    {
        int ida,idb,dut;
        ve *new_node = ASI_VE;
        //带权有向图
        getchar();
        scanf("<%d,%d,%d>",&ida,&idb,&dut);
        node_list[idb].index++; //入度加一
        new_node->position = idb;
        new_node->dut = dut;
        new_node->next = node_list[ida].link;
        node_list[ida].link = new_node;
        new_node->in_line = &road[temp]; //连接至对应边
        printf("SUCCESSFULLY INSERT THE LINE!-ID:%3d,FROM:%3d,TO:%3d\n",
               temp,ida,idb);
    }
    //初始化拓扑排序缓冲区栈空间
    for(temp=0;temp<node_account;temp++)
    {
        if(node_list[temp].index == 0)
        {
            node_list[temp].index = top_topo;
            top_topo = temp;
        }
    }
    int n=0;//计数
    printf("NOW PRINT TOPO\n");
    while (top_topo != -1)
    {
        ve *P = node_list[top_topo].link;
        int u = top_topo;
        printf("The %dth is %d\n",++n,node_list[top_topo].value);
        top_topo = node_list[top_topo].index;
        while (P!=NULL)
        {
            node_list[P->position].index--;
            if(node_list[P->position].index == 0)
            {
                node_list[P->position].index = top_topo;
                top_topo = P->position;
            }
            if(Ve[u]+P->dut > Ve[P->position])
            {
                Ve[P->position] = Ve[u]+P->dut;
            }
            P = P->next;
        }
        node_list[u].index = top_reverse_topo;
        top_reverse_topo = u;
    }
    //栈空，进行判断
    if(n<node_account)
    {
        printf("Error!The grapth has circle!\n");
        exit(1);
    }
    //初始化Vl
    for(temp=0;temp<node_account;temp++)
    {
        Vl[temp] = Ve[top_reverse_topo];
    }
    n = 0;
    printf("NOW PRINT REVERSE TOPO\n");
    while (top_reverse_topo!=-1)
    {
        ve *P = node_list[top_reverse_topo].link;
        int u = top_reverse_topo;
        printf("The %dth is %d\n",++n,node_list[top_reverse_topo].value);
        top_reverse_topo = node_list[top_reverse_topo].index;
        while (P!=NULL)
        {
            if(Vl[P->position]-P->dut < Vl[u])
            {
                Vl[u] = Vl[P->position] - P->dut;
            }
            P = P->next;
        }
    }
    // 计算边
    for(temp=0;temp<node_account;temp++)
    {
        ve *P = node_list[temp].link;
        while (P!=NULL)
        {
            P->in_line->line_e = Ve[temp];
            P->in_line->line_l = Vl[P->position]-P->dut;
            P->in_line->left = abs(P->in_line->line_e - P->in_line->line_l);
            P = P->next;
        }
    }
    // 输出边
    printf("NOW PRINT LINES\n");
    printf("%5s%6s%7s%8s\n","ID","E","L","LEFT");
    for(temp=0;temp<line_account;temp++)
    {
        printf("%5d%6d%7d%8d\n",
               temp,road[temp].line_e,road[temp].line_l,road[temp].left); 
    }
    return 0;
}