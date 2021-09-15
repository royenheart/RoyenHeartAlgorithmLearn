/*
    编写一个手机通讯录程序，能根据人员姓名查找电话号码。
    哈希表构造:
    根据给定关键字，由一定的哈希函数得到关键字对应的记录存放的地址值，方便查找
    即可根据关键字由一定的哈希函数直接查找到对应记录
    哈希函数构造需要注意因素：
        计算哈希函数所需时间
        关键字长度
        哈希表大小
        关键字分布情况
        记录的查找频率
*/

/*
    [2021.5.21]需要更进一步的分析
    本题哈希函数分析：
        关键字长度：
            名字，纯英文字符（均转换为大写），最长20个字符即20个字节
        哈希表大小：
            通讯录大小，400个
        关键字分布情况：
            20个字符，名字均有不同
        分析：
            由元音中最长的单词数，取前六个字符进行区分
            ASC1 ASC2 ASC3 ASC4 ASC5 ASC6
            相加：
                min = 65
                max = 90*6 = 540
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE_NAME 20
#define MAX_SIZE_PHONE 20
#define MAX_SIZE_LIST 400

typedef struct info
{
    /* 存放人员信息：姓名，性别，电话号码 */
    char name[MAX_SIZE_NAME];
    short sex; //性别 1:男，2：女
    char phone[MAX_SIZE_PHONE];
}info;

info list[MAX_SIZE_LIST];
int IS_DATA[MAX_SIZE_LIST] = {0}; //是否已经存放了记录

int HASH(char name[MAX_SIZE_NAME],int offset)
{
    char upper[MAX_SIZE_NAME] = {0};
    int temp;
    int reup = -1;
    int key = 0;
    strcpy(upper,name);
    while (upper[++reup]!=0)
    {
        //转换大小写
        upper[reup] = toupper(upper[reup]);
    }
    for(temp=0;temp<=5;temp++)
    {
        key += upper[temp];
    }
    return (key-40+offset)%MAX_SIZE_LIST;
}

int main(void)
{
    int temp;
    int info_account;
    //初始化通讯录
    for(temp=0;temp<MAX_SIZE_LIST;temp++)
    {
        memset(list[temp].name,0,MAX_SIZE_NAME);
        memset(list[temp].phone,0,MAX_SIZE_PHONE);
        list[temp].sex = 0;
    }
    printf("PLZ input the nnumber of the info\n");
    scanf("%d",&info_account);getchar();
    printf("PLZ input the specific info of the person\n"
           "The format is NAME SEX PHONE_NUMBER,a attribute a line\n"
           "SEX using M:stands for male,F:stands for female\n");
    for(temp=1;temp<=info_account;temp++)
    {
        char name[MAX_SIZE_NAME] = {0};
        char sex[2] = {0};
        char phone_number[MAX_SIZE_PHONE] = {0};
        int position,offset = 0;
        gets(name);gets(sex);gets(phone_number);
        position = HASH(name,offset);
        while(IS_DATA[position] == 1)
        {
            position = HASH(name,++offset);
        }
        IS_DATA[position] = 1;
        strcpy(list[position].name,name);
        strcpy(list[position].phone,phone_number);
        list[position].sex = (sex[0]=='M')?1:2;
    }
    printf("PLZ input a name to search for his/her info\n");
    char command[MAX_SIZE_NAME] = {0};
    gets(command);
    while (strcmp(command,"exit")!=0)
    {
        int offset = 0;
        int position = HASH(command,offset);
        while(strcmp(list[position].name,command)!=0 && IS_DATA[position]==1)
        {
            position = HASH(command,++offset);
        }
        if(IS_DATA[position] == 1)
        {
            printf("FIND!\n%s,%s,%s\n",list[position].name,(list[position].sex==1)?"Male":"Female",list[position].phone);
        }
        else
        {
            printf("NOT FIND!\n");
        }   
        memset(command,0,MAX_SIZE_NAME);
        gets(command);
    }
    return 0;
}