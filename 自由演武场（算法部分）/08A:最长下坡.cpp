#include <iostream>
#include <algorithm>
using namespace std;
//runtime error:数组越界
//注意计数变量的初始化！！！
int main()
{
    int n;
    int a[210];
    int cnt = 0, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int j = 0; j < n; j++)
    {
        cnt = 0; //注意计数变量的初始化！！！
        for(int i = 0; i < n; i++){
            if(a[i+j] > a[i+j+1])//必须是连续的下坡
                cnt++;
            else
                break;
        }
        res = max(res, cnt);
    }
    cout << res << endl;
    return 0;
}
