#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 101

typedef struct jobs {
    char *name;
    int time;
    int priority;
}jobs;

typedef struct heap {
    jobs list[MAXSIZE];
    int size;
}heap;

void exchange(jobs *a, jobs *b);
int compare(jobs A, jobs B);
void correct(heap *A, int i);

// 交换jobs元素
void exchange(jobs *a, jobs *b) {
    jobs c = *a;
    *a = *b;
    *b = c;
}

// 比较jobs大小(重载)
int compare(jobs A, jobs B) {
    if (A.priority > B.priority) {
        return 1;
    } else if (A.priority < B.priority) {
        return -1;
    } else {
        if (A.time != B.time)
            return (A.time > B.time)?1:-1;
        return 0;
    }
}

// 维护最小堆
void correct(heap *A, int i) {
    int min;
    int l = i * 2;
    int r = i * 2 + 1;
    if (l <= A->size && compare(A->list[l],A->list[i]) == -1) {
        min = l;
    } else {
        min = i;
    }
    if (r <= A->size && compare(A->list[r],A->list[min]) == -1) {
        min = r;
    }
    if (min != i) {
        exchange(&(A->list[i]),&(A->list[min]));
        correct(A,min);
    }
}

int main() {
    heap A;
    int n;
    A.size = 0;
    printf("how many jobs you want?\n");
    scanf("%d",&n);getchar();
    printf("plz insert the jobs with name priority time\n");
    for (int i = 1; i <= n; i++) {
        int pos = ++A.size;
        jobs tmp;
        tmp.name = (char*)malloc(MAXSIZE*sizeof(char));
        tmp.name = memset(tmp.name,0,MAXSIZE*sizeof(char));
        scanf("%s %d %d",tmp.name,&tmp.priority,&tmp.time);getchar();
        A.list[pos] = tmp;
    }
    // 建堆
    for (int i = A.size / 2 ; i >= 1 ; i--) {
        correct(&A,i);
    }
    // 排序
    for (int i = A.size ; i >= 1; i--) {
        printf("%s %d %d\n",A.list[1].name,A.list[1].priority,A.list[1].time);
        exchange(&(A.list[1]),&(A.list[i]));
        A.size--;
        correct(&A,1);
    }
}