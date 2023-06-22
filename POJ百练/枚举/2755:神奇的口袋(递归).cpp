#include <iostream>
#include <algorithm>
using namespace std;

//分解问题：给物品编号，从后向前处理
//选与不选第k个物品
int n, ans = 0;
int a[22];

int f(int w, int k)
{
    if(!w)
        return 1;
    if(w < 0 || k <= 0)
        return 0;
    return f(w, k-1) + f(w - a[k], k-1);
    
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << f(40, n) << endl;
    return 0;
}
