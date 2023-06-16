//较难的枚举题，需要考虑缩枚举空间和越界
#include <iostream>
#include <algorithm>
using namespace std;

int d, n;//炸弹威力d和路口数量n
int map[1025][1025] = { {0} };
int visited[1025][1025] = { {0} }; //避免有重复计算的点
struct Point{
    int x,y;
    Point(int i, int j):x(i),y(j) { }
};

vector<Point> vpt;

int main()
{
    cin >> d >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y, amt;
        cin >> x >> y >> amt;
        map[x][y] = amt;
        Point pt(x,y);
        vpt.push_back(pt);
    }
    //开始枚举
    int totrub = 0, totpt = 0;
    //totrub为垃圾数量，totpt为可以清理垃圾数最多的点个数
    //仅枚举屏幕周围的点
    for(int i = 0; i < n; i++) //屏幕的个数
    {
        Point pt = vpt[i];
        int _x = pt.x, _y = pt.y;
        //还需要考虑越界
        for(int l = _x - d; l <= _x + d; l++)
            for(int m = _y - d; m <= _y + d; m++)
            {
                //越界问题：
                if(l < 0 || l > 1024 || m < 0 || m > 1024)
                    continue;
                if(!visited[l][m])
                {
                    visited[l][m] = 1;
                    int temp = 0;
                    for(int j = -d; j <= d; j++){
                        for(int k = -d; k <= d; k++){
                            if((l+j) < 0 || (l+j) > 1024 || (m+k) < 0 || (m+k) > 1024)
                                continue;
                            if(map[l+j][m+k])
                                temp += map[l+j][m+k];
                        }
                    }
                    if(temp > totrub)
                    {
                        totrub = temp;
                        totpt = 1;
                    }
                    else if(temp == totrub)
                        totpt++;
                }
            }
    }
    cout << totpt << ' ' << totrub << endl;
    return 0;
}
