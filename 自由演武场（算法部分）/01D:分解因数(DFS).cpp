//还没完全弄明白深搜的原理
#include <iostream>
using namespace std;

int cnt = 0;
//对整数n进行分解，分解出的因数大于等于minfac的方案数
void dfs(int n, int minfac)
{
    for(int i = minfac; i <= n; i++)
    {
        if(n % i == 0)
            dfs(n / i, i); //每次都把n用因数i缩小，将n分解为 n = (n/i) * i两部分
        if(i == n)
            cnt++;
    }
}

int main()
{
    int N;
    cin >> N;
    int n;
    for(int i = 0; i < N; i++)
    {
        cnt = 0;
        cin >> n;
        dfs(n,2); //最小因数为2
        cout << cnt << endl;
    }
    return 0;
}
