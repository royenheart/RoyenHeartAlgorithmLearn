#ifndef __MANACHER_H_
#define __MANACHER_H_
#define MAX_LIST_SIZE 1000
//list:NDN list length:tree scale top_list:list length aux:AUX CHAR
int manacher(int list[], int length[], int top_list, int aux);

int manacher(int list[], int length[], int top_list, int aux)
{
    /* Manacher算法 */
    /* 用于寻找字符串中最长的回文子串 */
    int Manacher[MAX_LIST_SIZE] = {0};
    int Radius[MAX_LIST_SIZE] = {0}; // 回文半径
    int Amount;                      // 字符个数
    int i;
    int Pos_Mana = -1; // 字符串长度（右边界位置）
    /* R，p1，p2，cl，pl,C声明并初始化*/
    int R, p1, p2, cl, pl, C;
    R = -1;
    C = -1;
    /* 从二叉树中序遍历线性序列读入字符串并同时进行处理 */
    for (i = 1; i <= top_list + 1; i++)
    {
        Manacher[++Pos_Mana] = aux;
        Manacher[++Pos_Mana] = list[i - 1];
    }
    Manacher[++Pos_Mana] = aux;
    /* 算法开始 */
    for (p1 = 0; p1 <= Pos_Mana; p1++)
    {
        if (p1 > R)
        {
            int pos = p1;
            while (2 * p1 - pos >= 0 && Manacher[pos] == Manacher[2 * p1 - pos])
            {
                pos++;
            }
            pos--;
            Radius[p1] = pos - p1 + 1;
            R = pos;
            C = p1;
        }
        else
        {
            p2 = 2 * C - p1;
            cl = C - Radius[C] + 1;
            pl = p2 - Radius[p2] + 1;
            if (cl > pl)
            {
                Radius[p1] = R - p1 + 1;
            }
            else if (cl < pl)
            {
                Radius[p1] = Radius[p2];
            }
            else
            {
                int position = R + 1;
                while (position <= Pos_Mana && Manacher[position] == Manacher[2 * p1 - position])
                {
                    position++;
                }
                position--;
                Radius[p1] = position - p1 + 1;
                R = position;
                C = p1;
            }
        }
    }
    /* 判定输出最长回文子串 */
    /* 首先看manacher即添加辅助字符后的序列中不是辅助字符的项 */
    /* 将Radius和length中的整数型数据元素进行比较（-1忽略），若相同则为对称二叉树，找到最大对称二叉树 */
    /* 注意Radius中存储的是加入-1辅助后的半径，Length为整个子树的拥有的结点数 */
    /* length = 2*((Radius-1)/2)+1 */
    int length_pos = -1;
    int max_pos = -1, max_node = 0; // max_pos表示出现在哪棵子树（根结点来表达），max_node表示最大结点数
    for (i = 0; i <= Pos_Mana; i++)
    {
        if (Manacher[i] != aux)
        {
            length_pos++;
            if (length[length_pos] == 2 * ((Radius[i] - 1) / 2) + 1)
            {
                if (length[length_pos] > max_node)
                {
                    max_node = length[length_pos];
                    max_pos = length_pos;
                }
            }
        }
    }
    if (max_pos == -1)
    {
        printf("None");
    }
    else
    {
        printf("%d as the rank in the list(0 as start)\n%d as the root value\n%d max amounts of nodes", max_pos, list[max_pos], max_node);
    }
    return 0;
}
#endif