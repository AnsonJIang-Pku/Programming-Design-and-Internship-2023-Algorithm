//如何将二维dp数组转化为一维dp滚动数组：明白问题的思路
#include <iostream>
#include <algorithm>
using namespace std;

int N, M; //N: total num, M: max Volum
struct Charm{
    int w,d;
};
Charm cm[3500];
//dp[i][j]: 从前i个物品里选，使得体积不超过j的最大价值
int dp[13000] = { 0 }; //压缩:需要将状态都存储在一行里，否则MLE

int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> cm[i].w >> cm[i].d;
    for(int j = 0; j <= M; j++){
        if(cm[1].w <= j)
            dp[j] = cm[1].d;
        else
            dp[j] = 0;
    }
    for(int i = 2; i <= N; i++){ //第i个物品放不放
        for(int j = M; j >= 0; j--){ //体积不超过j
            if(j - cm[i].w >= 0)
                dp[j] = max(dp[j], dp[j-cm[i].w] + cm[i].d);
        }
    }
    cout << dp[M] << endl;
    return 0;
}
