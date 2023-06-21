//感觉就是找规律问题
#include <iostream>
#include <algorithm>
using namespace std;

//通过观察，发现n=2时可能情况为3；n>=4时，排除n=2的分割，可能情况均有两种
//因此得到递推公式: A_n = 3*A_{n-2} + 2*A_{n-4} + 2*A_{n-6} + ... +2*A_0;
//a4 = 3a_2 + 2
int main()
{
    int N, dp[31] = { 0 };
    //递推起点:
    dp[0] = 1; //只有一种覆盖: 不需要覆盖
    dp[2] = 3; //3*2的情况有三种覆盖
    //n为奇数时无法覆盖
    for(int i = 4; i <= 30; i++)
    {
        if(i % 2 != 0)
            continue;
        dp[i] += 3 * dp[i-2];
        for(int j = i-4; j >= 0; j--)
            dp[i] += 2 * dp[j];
    }
    //输出
    while(cin >> N && N != -1)
        cout << dp[N] << endl;
    return 0;
}
