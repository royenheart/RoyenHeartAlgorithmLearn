/*
中缀算数表达式的运算
根据中缀算术表达式
使用栈实现算术优先级运算
得出算数表达式的值
算术优先级计算：
栈性质：后进先出，故进行运算的时候
先弹出运算符栈顶元素（运算符进行运算）
即优先级最高的算数符号应该在栈顶，
然后依次往下执行（确保优先级）
*/

/* 实现乘方运算
 * 
 * 
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000
#define plus 0
#define minus 1
#define multi 2
#define div 3
#define lbracket 4
#define rbracket 5
#define invotion 6

int OPNUM[MAX_SIZE];
int OPSYM[MAX_SIZE];

//0:equal 1:bigger 2:smaller
int priviledge_list[7][7]={0,0,2,2,2,1,2,
                           0,0,2,2,2,1,2,
                           1,1,0,0,2,1,2,
                           1,1,0,0,2,1,2,
                           1,1,1,1,0,1,1,
                           2,2,2,2,2,0,2,
                           1,1,1,1,1,1,0};
                           
#define PList priviledge_list

//0:OPNUM 1:OPSYM
int top[2]={-1,-1};

int operation(int a,int b,int type)
{
    if(type == plus){return a+b;}
    else if(type == minus){return a-b;}
    else if(type == multi){return a*b;}
    else if(type == div)
    {
        if(b==0){printf("DIV 0!");exit(1);}
        return a/b;
    }
    else if(type == lbracket){return a;}
    else if(type == invotion){return (int)pow(a,b);}
}

int main(void)
{
    int pos_ex = 0;
    char expression[MAX_SIZE]={0};
    OPNUM[++top[0]] = 0;
    printf("PLZ input the expression\n");
    scanf("%s",expression);
    while (expression[pos_ex]!='\0')
    {
        char in_ex = expression[pos_ex];
        if (isalnum(in_ex))
        {
            int opnum = 0;
            opnum = opnum*10 + (in_ex-48);
            while (isalnum(expression[++pos_ex]))
            {
                opnum = opnum*10 + (expression[pos_ex]-48);
            }
            pos_ex--;
            OPNUM[++top[0]] = opnum;
        }
        else
        {
            int opsym;
            if(in_ex == '+')
            {
                opsym = plus;
            }
            else if(in_ex == '-')
            {
                opsym = minus;
            }
            else if(in_ex == '*')
            {
                opsym = multi;
            }
            else if(in_ex == '/')
            {
                opsym = div;
            }
            else if(in_ex == '(')
            {
                opsym = lbracket;
            }
            else if(in_ex == '^')
            {
                opsym = invotion;
            }
            else
            {
                opsym = rbracket;
            }
            //0:equal 1:bigger 2:smaller
            if(top[1]==-1)
            {
                OPSYM[++top[1]] = opsym;
                if(opsym == lbracket)
                {
                    for(int i=0;i<=3;i++)
                    {
                        PList[i][4] = 1;
                    }
                }
            }
            else
            {
                if(PList[opsym][OPSYM[top[1]]] == 1)
                {
                    OPSYM[++top[1]] = opsym;
                    if(opsym == lbracket)
                    {
                        for(int i=0;i<=3;i++)
                        {
                            PList[i][4] = 1;
                        }
                    }
                }
                else
                {
                    if(top[0]<2){printf("Format Error");exit(1);}
                    while (PList[opsym][OPSYM[top[1]]]!=1 && top[1]>-1)
                    {
                        OPNUM[top[0]-1] = operation(OPNUM[top[0]-1],OPNUM[top[0]],OPSYM[top[1]]);
                        if(OPSYM[top[1]] == lbracket){top[1]--;break;}
                        top[1]--;
                        top[0]--;
                    }
                    if(opsym!=rbracket)
                    {
                        OPSYM[++top[1]] = opsym;
                    }
                    else
                    {
                        for(int i=0;i<=3;i++)
                        {
                            PList[i][4] = 2;
                        }
                    }
                }
            }           
        }
        pos_ex++;
    }
    while (top[1]!=-1 && top[0]!=-1)
    {
        OPNUM[top[0]-1] = operation(OPNUM[top[0]-1],OPNUM[top[0]],OPSYM[top[1]]);
        top[0]--;
        top[1]--;
    }
    printf("The final number is %d\n",OPNUM[top[0]]);
    return 0;
}