//简单的深搜
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    //储存横纵坐标
    int i;
    int j;
    Node(){
        i = -1; j = -1;
    }
};

#define INFINITE 500
int maze[6][6], colored[6][6] = { 0 }; //colored记录某点是否走过
int depth;
int minSteps = INFINITE;
Node path[40];
Node bestPath[40];

void Dfs(int x, int y)
{
    if(x == 4 && y == 4)
    {
        path[depth].i = 4; path[depth].j = 4;
        if(depth < minSteps)
        {
            minSteps = depth;
            for(int i = 0; i <= depth; i++)
                bestPath[i] = path[i];
        }
        return;
    }
    if(colored[x][y]) //x,y为旧点
        return;
    colored[x][y] = 1;
    path[depth].i = x; path[depth].j = y;
    depth++;
    //需要判断越界
    if(!maze[x+1][y] && x < 4) Dfs(x+1, y);
    if(!maze[x][y+1] && y < 4) Dfs(x, y+1);
    if(!maze[x][y-1] && y > 0) Dfs(x, y-1);
    if(!maze[x-1][y] && x > 0) Dfs(x-1, y);
    
    colored[x][y] = 0; //将x,y恢复为新点
    depth--;
    return;
}

int main()
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> maze[i][j];
    depth = 0;
    Dfs(0,0);
    for(int i = 0; i <= minSteps; i++)
        cout << "(" << bestPath[i].i << ", " << bestPath[i].j << ")" << endl;
    return 0;
}
