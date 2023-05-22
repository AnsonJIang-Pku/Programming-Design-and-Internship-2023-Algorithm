#include <iostream>
//最大最小问题无脑二分。
//可是也需要对问题进行抽象：明确对什么有序的东西进行二分，l和r分别是什么，出口条件
using namespace std;

int a[50010] = { 0 },L,N,M;
//一串数，去掉中间几个，st剩下的最小距离最长
//首先以0为起点，如果从0到某个点的距离小于mid，那么中间的都扔掉；
//如果出现了从0到某个点的距离大于mid，那么以新的点位坐标原点(更新d)，继续做以上步骤
bool check(int x)
{
    int cnt = 0,d = 0;
    for(int i = 1; i <= N; i++)
    {
        if(a[i] - d < x) //=x是不对的，因为不能取到最右侧端点（这个没想清楚）
            cnt++;
        else
            d = a[i];
    }
    if(L - d < x)
        cnt++;
    return cnt <= M;
}

int main()
{
    cin >> L >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> a[i];
    int l = 0, r = L, mid;
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
    return 0;
}
