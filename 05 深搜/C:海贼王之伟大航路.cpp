#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//TSP问题，采用状态压缩动态规划
//Traveling Salesman Problem
int N;
int map[17][17] = { {0} };
int dp[17][(1 << 16)] = {{0}}; //求最短路径，需要初始化成大值

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> map[i][j];
    memset(dp,0x3f,sizeof(dp));
    dp[1][1] = 0;
    //状压dp, S为枚举的所有状态, 二进制位代表某个点是否存在
    //终点不在状态中的写法
    for(int S = 1; S < (1<<N); S++){ //枚举所有状态，向集合中加入新点的操作被枚举替代
        for(int j = 1, _j = 1; j <= N; j++, _j <<= 1){ //枚举最后一步的起点j
            for(int k = 1, _k = 1; k <= N; k++, _k <<= 1){ //枚举终点k
                if( !(S & _k) && (S & _j)) //此时j和k点都在集合里，都走过
                    dp[k][S | _k] = min(dp[k][S | _k], dp[j][S] + map[j][k]);
            }
        }
    }
    cout << dp[N][(1<<N)-1] << endl;
    return 0;
}

//ok: 终点在状态中的写法（区别在递推式）
/*
for(int S = 1; S < (1<<N); S++){ //枚举所有状态，向集合中加入新点的操作被枚举替代
    for(int j = 1, _j = 1; j <= N; j++, _j <<= 1){ //枚举最后一步的起点j
        for(int k = 1, _k = 1; k <= N; k++, _k <<= 1){ //枚举终点k
            if( (S & _j) && (S & _k)) //此时j和k点都在集合里，都走过
                dp[k][S] = min(dp[k][S], dp[j][S^_k] + map[j][k]);
        }
    }
}
*/

//如果这样写，实际上多移了一位:
/*
for(int S = 0; S < (1<<N); S++){ //枚举所有状态，向集合中加入新点的操作被枚举替代
       for(int j = 1; j <= N; j++){ //枚举最后一步的起点j
           for(int k = 1; k <= N; k++){ //枚举终点k
               if( (S & (1<<j)) && (S & (1<<k))) //此时j和k点都在集合里，都走过
                   dp[k][S] = min(dp[k][S], dp[j][S^(1<<k)] + map[j][k]);
           }
       }
   }
*/
