#include <iostream>
#include <string>
#include <queue>
using namespace std;
//合理运用pair类模版,在C++11可以利用花括号进行赋值和初始化
//也可以直接使用make_pair(..., ...)进行赋值和初始化
int map[7][7] = { {0} }, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
bool vis[7][7] = { {false} };
string ans[7][7];
queue<pair<int, int>> q;

//输出最短路径
int main() {
    vis[1][1] = true;
    ans[1][1] = "(0, 0)\n";
    q.push({ 1,1 });
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++){
            cin >> map[i][j];
            map[i][j] = 1 - map[i][j];
        }
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = now.first + dx[i], yy = now.second + dy[i];
            if (!map[xx][yy] || vis[xx][yy] || xx < 1 || xx>5 || yy < 1 || yy > 5)
                continue;
            q.push({ xx,yy });
            vis[xx][yy] = true;
            //star: 这一步是关键，把每次的答案都附加在之前答案的后面
            ans[xx][yy] = ans[now.first][now.second] + '(' + to_string(xx - 1) + ", " + to_string(yy - 1) + ")\n";
            //广搜最先到达的一定是最短的
            if (xx == 5 && yy == 5) {
                cout << ans[5][5];
                return 0;
            }
        }
    }
}
