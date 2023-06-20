//和数字三角形很像的一道题
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[110][110];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};//方向向量
//dp[i][j]代表从(i,j)点出发，能经过的最长路径的长度
int dp[110][110] = { { 1 } }; //初始化为1，代表如果不更新，那么四周的点都比这一点高
int R,C;

struct Point{
    int x,y;
    int h;
    Point(int _x, int _y, int _h):x(_x),y(_y),h(_h) { }
    bool operator<(Point p)const{
        return h < p.h;
    }
};
vector<Point> vpt;//结构体数组vpt

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            vpt.push_back(Point(i,j,map[i][j]));
            dp[i][j] = 1; //为什么在一开始初始化就不行呢？
        }
    sort(vpt.begin(),vpt.end());//按照高度从小到大排序
    for(int i = 0; i < vpt.size(); i++)
    {
        Point now = vpt[i];
        for(int j = 0; j < 4; j++){
            int xx = now.x + dx[j], yy = now.y + dy[j];
            //判断xx和yy是否越界,x是从0~R-1,y是从0~C-1
            if(xx < 0 || xx > R-1 || yy < 0 || yy > C-1)
                continue;
            if(map[xx][yy] < now.h)
                dp[now.x][now.y] = max(dp[now.x][now.y], dp[xx][yy] + 1);
        }
    }
    int res = 1;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            res = max(res, dp[i][j]);
    cout << res << endl;
    return 0;
}
