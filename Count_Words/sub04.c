/*
（行号由换行符确定'\n'）
数据元素：单词
抽象：
1.单词名
2.单词位置（首次出现）（行号，相对于该行的偏移量）
3.单词出现的次数
打开文本文件
开始读取数据（一个字符为单位进行读取）
读到的字符为字母
    在临时字符数组中进行存储
    继续下一个读取操作
读到的字符不为字母
    偏移量+1
    对临时字符数组中存储的字符串进行运算
    若字符串在单词链表中不存在
        按字典序动态排序进行插入
        按一定的数值赋值
            总次数设为1，设定出现的位置
            存储单词名
    若字符串在单词链表中已存在
        对对应单词的总次数加1
    若读到的字符为换行符
        行数+1，偏移量=0
    清空临时字符数组
    进行下一步读取操作
关闭文本文档
输出对应要求
结束程序
字符比较（按顺序比较--用string库）
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define lenWls 40

typedef struct word_list wls;
struct word_list
{
    char name[lenWls];
    int pos_line;
    int pos_col;
    int amounts;
    wls *next;
};

int main(void)
{
    //对单词链表采用升序排列
    FILE *p;
    p = fopen("example2.txt","r");
    int pos_inter_char = -1;
    int line,col;
    char word;
    char inter_char[lenWls];
    memset(inter_char,0,lenWls);
    line = 1;col = 0;
    wls *wlsH,*wlsP;
    wlsH = (wls*)malloc(sizeof(wls));
    wlsH->next = wlsH;
    while (!feof(p))
    {
        word = fgetc(p);
        if(isalpha(word))
        {
            inter_char[++pos_inter_char] = word;
        }
        else
        {
            if(!inter_char[0]){continue;}
            memset(wlsH->name,0,lenWls);
            col++;
            wls *pre;
            wlsP = wlsH->next;strcat(wlsH->name,inter_char);pre = wlsH;
            while (strcmp(inter_char,wlsP->name)>0)
            {
                pre = wlsP;
                wlsP = wlsP->next;
            }
            if(!strcmp(inter_char,wlsP->name) && wlsP!=wlsH)
            {
                wlsP->amounts++;
            }
            else
            {
                wls *nw = (wls*)malloc(sizeof(wls));
                nw->amounts = 1;
                memset(nw->name,0,lenWls);
                strcat(nw->name,inter_char);
                pre->next = nw;
                nw->pos_col = col;
                nw->pos_line = line;
                nw->next = wlsP;
            }
            if(word=='\n')
            {
                line++;col=0;
            }
            memset(inter_char,0,lenWls);
            pos_inter_char = -1;
        }
    }
    fclose(p);
    wlsP = wlsH->next;
    printf("%-40s amounts line col\n","Name");
    while (wlsP!=wlsH)
    {
        printf("%-40s %-7d %-4d %-3d\n",wlsP->name,wlsP->amounts,wlsP->pos_line,wlsP->pos_col);
        wlsP = wlsP->next;
    }
    char command[lenWls];
    memset(command,0,lenWls);
    printf("INPUT THE WORD YOU WANT TO FIND\n"
           "INPUT EXIT TO QUIT THE SEARCH\n");
    do
    {
        gets(command);
        wlsP = wlsH->next;
        while (wlsP!=wlsH)
        {
            if(!strcmp(command,wlsP->name))
            {
                printf("FIND!\n");
                printf("%-40s amounts line col\n","Name");
                printf("%-40s %-7d %-4d %-3d\n",wlsP->name,wlsP->amounts,wlsP->pos_line,wlsP->pos_col);
                break;
            }
            wlsP = wlsP->next;
        }
        if(wlsP==wlsH){printf("NOT FIND!\n");}
        memset(command,0,lenWls);
    } while (!strcmp(command,"exit"));
    // NOW FREE THE LINK LIST
    wlsP = wlsH->next;
    while (wlsP!=wlsH)
    {
        free(wlsP);
        wlsP = wlsP->next;
    }
    free(wlsH);
    return 0;
}