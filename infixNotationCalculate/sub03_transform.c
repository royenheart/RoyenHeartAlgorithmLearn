/*
实现
中缀、前缀、后缀
算数表达式的相互转换
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000
#define plus 0
#define minus 1
#define multi 2
#define div 3
#define lbracket 4
#define rbracket 5
#define equal 0
#define bigger 1
#define smaller 2

int OPSYM[MAX_SIZE];
int top[1]={-1};

//0:equal 1:bigger 2:smaller
int priviledge_list[6][6]={0,0,2,2,2,1,
                           0,0,2,2,2,1,
                           1,1,0,0,2,1,
                           1,1,0,0,2,1,
                           1,1,1,1,0,1,
                           2,2,2,2,2,0};
#define PList priviledge_list

//implement
int translate(int code);
int lock_lbracket(void);
char *convert_NDN_NND(const char *NDN);
char *convert_NDN_DNN(const char *NDN);

int translate(int code)
{
    if(code == plus)
    {
        return '+';
    }
    else if(code == minus)
    {
        return '-';
    }
    else if(code == multi)
    {
        return '*';
    }
    else if(code == div)
    {
        return '/';
    }
    else if(code == lbracket)
    {
        return '(';
    }
    else
    {
        return ')';
    }
}

int lock_lbracket(void)
{
    int i=0;
    if(PList[0][4]==smaller)
    {
        for(;i<=3;i++)
        {
            PList[i][4] = bigger;
        }
    }
    else
    {
        for(;i<=3;i++)
        {
            PList[i][4] = smaller;
        }
    }
    return 1;
}

//need create OPNUM
char *convert_NDN_DNN(const char *NDN)
{
    int pos_NDN=0;
    char get,*DNN;
    DNN = (char*)malloc(sizeof(char)*MAX_SIZE);
    memset(DNN,0,MAX_SIZE);
    while ((get = NDN[pos_NDN])!='\0')
    {
        if(isalnum(get))
        {
            int number = (get - 48);
            char number_char[MAX_SIZE]={0};
            while (isalnum(get = NDN[++pos_NDN]))
            {
                number = number*10 + (get-48);
            }
            itoa(number,number_char,10);
            strcat(number_char,DNN);
            strcpy(DNN,number_char);
        }
        else
        {
            int opsym;
            if(get == '+')
            {
                opsym = plus;
            }
            else if(get == '-')
            {
                opsym = minus;
            }
            else if(get == '*')
            {
                opsym = multi;
            }
            else if(get == '/')
            {
                opsym = div;
            }
            else if(get == '(')
            {
                opsym = lbracket;
            }
            else
            {
                opsym = rbracket;
            }
            if(top[0]==-1)
            {
                OPSYM[++top[0]] = opsym;
                if(opsym == lbracket)
                {
                    lock_lbracket();
                }
            }
            else if(PList[opsym][OPSYM[top[0]]] == bigger)
            {
                OPSYM[++top[0]] = opsym;
                lock_lbracket();
            }
            else
            {
                while (PList[opsym][OPSYM[top[0]]]!= bigger && top[0]>-1)
                {
                    if(OPSYM[top[0]] == lbracket){top[0]--;break;}
                    char opsym_char[2]={0};
                    opsym_char[0] = translate(OPSYM[top[0]]);
                    strcat(opsym_char,DNN);
                    strcpy(DNN,opsym_char);
                    top[0]--;
                }
                if(opsym != rbracket)
                {
                    OPSYM[++top[0]] = opsym;
                }
                else
                {
                    lock_lbracket();
                }
            }
            pos_NDN++;
        }
    }
    while (top[0]>-1)
    {
        char opsym_char[2]={0};
        opsym_char[0] = translate(OPSYM[top[0]]);
        strcat(opsym_char,DNN);
        strcpy(DNN,opsym_char);
        top[0]--;
    }
    return DNN;
}

char *convert_NDN_NND(const char *NDN)
{
    int pos_NDN=0;
    char get,*NND;
    NND = (char*)malloc(sizeof(char)*MAX_SIZE);
    memset(NND,0,MAX_SIZE);
    while ((get = NDN[pos_NDN])!='\0')
    {
        if(isalnum(get))
        {
            int number = (get - 48);
            char number_char[MAX_SIZE]={0};
            while (isalnum(get = NDN[++pos_NDN]))
            {
                number = number*10 + (get-48);
            }
            itoa(number,number_char,10);
            strcat(NND,number_char);
        }
        else
        {
            int opsym;
            if(get == '+')
            {
                opsym = plus;
            }
            else if(get == '-')
            {
                opsym = minus;
            }
            else if(get == '*')
            {
                opsym = multi;
            }
            else if(get == '/')
            {
                opsym = div;
            }
            else if(get == '(')
            {
                opsym = lbracket;
            }
            else
            {
                opsym = rbracket;
            }
            if(top[0]==-1)
            {
                OPSYM[++top[0]] = opsym;
                if(opsym == lbracket)
                {
                    lock_lbracket();
                }
            }
            else if(PList[opsym][OPSYM[top[0]]] == bigger)
            {
                OPSYM[++top[0]] = opsym;
                lock_lbracket();
            }
            else
            {
                while (PList[opsym][OPSYM[top[0]]]!= bigger && top[0]>-1)
                {
                    if(OPSYM[top[0]] == lbracket){top[0]--;break;}
                    char opsym_char[2]={0};
                    opsym_char[0] = translate(OPSYM[top[0]]);
                    strcat(NND,opsym_char);
                    top[0]--;
                }
                if(opsym != rbracket)
                {
                    OPSYM[++top[0]] = opsym;
                }
                else
                {
                    lock_lbracket();
                }
            }
            pos_NDN++;
        }
    }
    while (top[0]>-1)
    {
        char opsym_char[2]={0};
        opsym_char[0] = translate(OPSYM[top[0]]);
        strcat(NND,opsym_char);
        top[0]--;
    }
    return NND;
}

int main(void)
{
    char NDN[MAX_SIZE]={0};
    char *NND,*DNN;
    printf("PLZ input the DNN expressions\n");
    scanf("%s",NDN);getchar();
    printf("%s\n",NND = convert_NDN_NND(NDN));
    top[0] = -1;
    printf("%s\n",DNN = convert_NDN_DNN(NDN));
    return 0;
}