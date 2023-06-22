//检查边界:动规一定要仔细检查网格的上边界和左边界(i=0和j=0)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//分解问题：给物品编号，从后向前处理
//选与不选第k个物品
//注意递归到动规的转化：变量对应、加入初始化、递推公式对应
int n;
int a[22];
int dp[42][22]; //dp[i][j]: 利用前j件物品凑出体积i

int main()
{
    cin >> n;
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[0][i] = 1; //利用任意件物品凑出体积0：1种方法
    }
    //检查边界:动规一定要仔细检查网格的上边界和左边界(i=0和j=0)
    dp[0][0] = 1;
    for(int i = 1; i <= 40; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j-1];
            if(i - a[j] >= 0) //一开始这里少了=
                dp[i][j] += dp[i-a[j]][j-1];
        }
    }
    cout << dp[40][n] << endl;
    return 0;
}
