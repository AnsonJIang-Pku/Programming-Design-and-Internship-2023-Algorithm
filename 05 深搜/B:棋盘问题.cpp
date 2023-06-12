#include <iostream>
using namespace std;
//很像N皇后问题
//注意在某行放置了棋子，那么这一行不能再放了
/*将放棋子这个问题分解为以下几步：
 0. 递归出口：没有剩余棋子，nCase加一；放到最后一行了还有剩余，不成立。
 1. 考虑某一行，有两种情况：放置棋子，不放置棋子
 2. 如果不放置棋子，剩余数量不变，在下一行开始递归；
 3. 如果放置棋子，按照某一列是否放置过棋子进行搜索；
 */
int n,k;
char map[8][8];
bool col_visited[8] = { false };//key:记录某一列是否放置过棋子（行的情况被包含在了自变量中）
int nCase;

void NChess(int row, int nLeft)
{
    //递归出口，棋子摆放完毕
    if(!nLeft){
        nCase++;
        return ;
    }
    else if(row > n && nLeft > 0) //摆不完了，不能这么摆
        return ;
    NChess(row + 1, nLeft); //这一行没有摆
    for(int j = 0; j < n; j++) //在这行摆了，尝试列
    {
        if(!col_visited[j] && map[row][j] == '#'){
            col_visited[j] = 1;
            NChess(row + 1, nLeft - 1);
            col_visited[j] = 0;
        }
    }
}

int main()
{
    while(cin >> n >> k && n != -1) //利用这种方式来判断结束
    {
        nCase = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> map[i][j];
        NChess(0,k);
        cout << nCase << endl;
    }
    return 0;
}
