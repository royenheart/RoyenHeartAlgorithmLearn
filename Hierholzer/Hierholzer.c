/* 
    Hierholzer算法
    求图中的欧拉回路
*/
#include <stdio.h>
#include <stdlib.h>

#define N 1001

typedef struct vertex vertex;
typedef struct adjcent_vertex adjve;
struct vertex {
    int value;
    adjve *head;
};
struct adjcent_vertex {
    int pos;
    adjve *next;
};

vertex graph[N]; // 不使用0位置
int stack[N],top = -1;

int hierholzer(int rank) {
    if(graph[rank].head->next == NULL) {
        stack[++top] = rank;
    } else {
        adjve *tmp = graph[rank].head->next;
        int to = tmp->pos;
        graph[rank].head->next = tmp->next;
        free(tmp);
        adjve *p,*pre;
        pre = graph[to].head;
        p = graph[to].head->next;
        while (p->pos != rank)
        {
            pre = p;
            p = p->next;
        }
        pre->next = p->next;
        free(p);
        hierholzer(to);
        if(graph[rank].head->next == NULL) {
            stack[++top] = rank;
        }
    }
    return 0;
}

int main(int argc,char *argv[]) {
    /* 使用邻接表存储图 */
    int amount,i,stf,eamo;
    scanf("%d",&amount);
    for(i = 1;i <= amount;i++) {
        scanf("%d",&graph[i].value);
        graph[i].head = (adjve*)malloc(sizeof(adjve));
        graph[i].head->next = NULL;
    }
    scanf("%d",&eamo);
    for(i = 1;i <= eamo;i++) {
        int a,b;
        adjve *tmp;
        scanf("%d %d",&a,&b);
        tmp = (adjve*)malloc(sizeof(adjve));
        tmp->pos = b;
        tmp->next = graph[a].head->next;
        graph[a].head->next = tmp;
        tmp = (adjve*)malloc(sizeof(adjve));
        tmp->pos = a;
        tmp->next = graph[b].head->next;
        graph[b].head->next = tmp;
    }
    scanf("%d",&stf);
    hierholzer(stf);
    for(;top>=0;top--) {
        printf("%d ",stack[top]);
    }
    return 0;
}