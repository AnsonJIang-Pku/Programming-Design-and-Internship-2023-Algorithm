#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;
double V[10010],res;
int m,n; //m为派的数量，n为朋友数量，实际人数n+1
double eps = 1e-5,l,r;

bool Satisfy()
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        count += int (V[i]/res);
    }
    return count >= n + 1;
}

int main()
{
    cin >> m >> n;
    for(int i = 0; i < m; i++)
    {
        cin >> V[i];
        V[i] = M_PI * V[i] *V[i];
    }
    sort(V,V+m);
    l = V[0] / (n + 1); //二分查找的初始最小值
    r = V[m-1];         //二分查找的初始最大值
    
    while((r - l) > eps)
    {
        res = (r + l) / 2;
        if (Satisfy())
            l = res;
        else
            r = res;
    }
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}
