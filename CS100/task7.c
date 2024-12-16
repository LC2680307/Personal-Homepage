#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************Functions******************************/
/* You need to check whether the given `mahjongHand` is win.
 * If wins, return 1, otherwise, return 0
 * The length of `mahjongHand` is guaranteed to be 14.
 * All tiles are guaranteed to be legal.
 */

int change(int PAI[38],char* hand[14]);
int Hu(int PAI[38]);
int Remain(int PAI[38]);
char *PAIDUI[34]={"1p","2p","3p","4p","5p","6p","7p","8p","9p",  \
                 "1s","2s","3s","4s","5s","6s","7s","8s","9s",  \
                 "1m","2m","3m","4m","5m","6m","7m","8m","9m",  \
                 "1z","2z","3z","4z","5z","6z","7z"};

int change(int PAI[38],char* hand[14])
{
    for(int i=0;i<14;i++)
        {
            if (hand[i][1]=='m')
            {
                PAI[0+hand[i][0]-48]+=1;
            }

            if (hand[i][1]=='p')
            {
                PAI[10+hand[i][0]-48]+=1;
            }

            if (hand[i][1]=='s')
            {
                PAI[20+hand[i][0]-48]+=1;
            }
            
            if (hand[i][1]=='z')
            {
                PAI[30+hand[i][0]-48]+=1;
            }
        }
    return PAI[38];
}

// 判断和牌的递归函数
int Hu(int PAI[38])
{
    static int JIANG = 0;            // 将牌标志，即牌型“三三三三二”中的“二”
    if( !Remain(PAI) ) return 1;     // 递归退出条件：如果没有剩牌，则和牌返回
    for(int i=1;i<38;i++)  // 找到有牌的地方，i就是当前牌, PAI[i]是个数
    {
    // 3张组合(大对)
    if ( PAI[i] >= 3 )               // 如果当前牌不少于3张
    {
        PAI[i] -= 3;                 // 减去3张牌
        if( Hu(PAI) ) return 1;      // 如果剩余的牌组合成功，和牌
        PAI[i] += 3;                 // 取消3张组合
    }
    // 2张组合(将牌)
    if ( !JIANG && PAI[i] >= 2 )     // 如果之前没有将牌，且当前牌不少于2张
    {
        JIANG = 1;                   // 设置将牌标志
        PAI[i] -= 2;                 // 减去2张牌
        if( Hu(PAI) ) return 1;      // 如果剩余的牌组合成功，和牌
        PAI[i] += 2;                 // 取消2张组合
        JIANG = 0;                   // 清除将牌标志
    }
    
    if ( i > 30 )    return 0;       // “东南西北中发白”没有顺牌组合，不和
    // 顺牌组合，注意是从前往后组合！
    if( i%10 != 8 && i%10 != 9  &&   // 排除数值为8和9的牌
         PAI[i+1] && PAI[i+2] )      // 如果后面有连续两张牌
    {
        PAI[i]--;
        PAI[i+1]--;
        PAI[i+2]--;                  // 各牌数减1
        if( Hu(PAI) ) return 1;      // 如果剩余的牌组合成功，和牌
        PAI[i]++;
        PAI[i+1]++;
        PAI[i+2]++;                  // 恢复各牌数
    }
    // 无法全部组合，不和！
    }
    return 0;
}
// 检查剩余牌数
int Remain(int PAI[38])
{
    int sum = 0;
    for(int i=1;i<38;i++)
        sum += PAI[i];
    return sum;
}



int CheckWin(char* mahjongHand[])
{   
    int PAI[38] = {0};
    PAI[38] = change(PAI,mahjongHand);
    for(int i=0;i<38;i++){
        printf("%d ",PAI[i]);
    }
    printf("\n");
    if( Hu(PAI) )
        return 1;
    else
        return 0;
}

/* You need to count the number of different tiles that
 * lead him to win. 
 * The length of `currentTiles` is guaranteed to be 13,
 * all tiles are guaranteed to be legal. You should ignore 
 * the tiles that are used up (already 4 in his hand). 
 * Return the number of different tiles that leads him to win.
 */
int CountWaitingTiles(char* currentTiles[])
{
    int num;
    int PAI[38] = {0};
    for(int i=0;i<34;i++){
        currentTiles[14]=PAIDUI[i]; //抽牌
        PAI[38] = change(PAI,currentTiles);
        for(int i=0;i<38;i++){
            if(PAI[i]>4){ //确认无多于四张的牌
                break;
            }
            else{
                if(CheckWin(currentTiles)==1){ //判断听牌
                    num+=1;
                }
                else{
                    break;
                }
            }
        }

    }
    return num;
}

/*****************************Your Main Function*************************************/
// DO NOT submit main function to OJ, or compile error may happen!
int main()
{
    /*************** Part1 ***************/
    //char* hand[14] = {"1s", "2z", "3m", "5p", "6s", "5p", "3z", "5z", \
    //                  "4z", "7m", "9s", "9p", "3z", "4s"};
    //char* hand[14] = {"1s", "1s", "1s", "2p", "2p", "2p", "5p", "6p", \
    //                   "7p", "3z", "3z", "9s", "3z", "9s"};
    //int result = CheckWin(hand);
    //printf ("Gezi Wang %s the game.\n", result == 1 ? "wins" : "does not win");

    /*************** Part2 ***************/
     char* currentTiles[13] = {"1s", "1s", "1s", "2s", "3s", "4s", "5s", "6s", \
                          "7s", "8s", "9s", "9s", "9s"};
     printf ("The number of different tiles he is waiting for is: %d\n", CountWaitingTiles(currentTiles));
    return 0;
}