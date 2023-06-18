//递推的关系不是很好理解
#include <iostream>
using namespace std;

//返回数字n分解成由大于等于minfac的因数的乘积的形式 的分解方案数
int solve(int n, int minfac)
{
    //递归出口，n为1时，只有一种分解方案数
    if(n == 1)
        return 1;
    int cnt = 0;
    for(int i = minfac; i <= n; i++)
    {
        if(n % i == 0) //如果i是n的因数，那么继续求除去因数i的所有可能分解数
            cnt += solve(n/i, i);
    }
    return cnt;
}

int main()
{
    int N;
    cin >> N;
    int n;
    for(int i = 0; i < N; i++)
    {
        cin >> n;
        cout << solve(n,2) << endl;
    }
    return 0;
}
