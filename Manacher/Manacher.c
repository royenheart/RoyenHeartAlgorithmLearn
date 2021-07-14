#include <stdio.h>

#define MAX_SIZE 1000
#define Aux_Char '#' // 辅助字符

int main() {
    /* Manacher算法 */
    /* 用于寻找字符串中最长的回文子串 */
    char Manacher[MAX_SIZE] = {0};
    int Radius[MAX_SIZE] = {0}; // 回文半径
    int Amount; // 字符个数
    int i;
    int Pos_Mana = -1; // 字符串长度（右边界位置）
    /* R，p1，p2，cl，pl,C声明并初始化*/
    int R,p1,p2,cl,pl,C;
    R = -1;C = -1;
    /* 读入字符串并同时进行处理 */
    scanf("%d",&Amount);getchar();
    for(i = 1;i <= Amount;i++) {
        Manacher[++Pos_Mana] = Aux_Char;
        scanf("%c",&Manacher[++Pos_Mana]);
    }
    Manacher[++Pos_Mana] = Aux_Char;
    /* 算法开始 */
    for(p1 = 0;p1 <= Pos_Mana;p1++) {
        if(p1 > R) {
            int pos = p1;
            while (2*p1-pos >= 0 && Manacher[pos] == Manacher[2*p1-pos]) {
                pos++;
            }
            pos--;
            Radius[p1] = pos-p1+1;
            R = pos;
            C = p1;
        } else {
            p2 = 2*C - p1;
            cl = C - Radius[C] + 1;
            pl = p2 - Radius[p2] + 1;
            if(cl > pl) {
                Radius[p1] = R - p1 + 1;
            } else if(cl < pl) {
                Radius[p1] = Radius[p2];
            } else {
                int position = R + 1;
                while (position <= Pos_Mana && Manacher[position] == Manacher[2*p1-position])
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
    /* 输出 */
    for(i = 0;i <= Pos_Mana;i++) {
        printf("%c ",Manacher[i]);
    }
    printf("\n");
    for(i = 0;i <= Pos_Mana;i++) {
        printf("%d ",Radius[i]);
    }
    return 0;
}