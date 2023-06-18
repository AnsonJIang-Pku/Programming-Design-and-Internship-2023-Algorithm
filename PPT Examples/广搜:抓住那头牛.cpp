#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 100000

int N,K;
int visited[MAXN + 10] = { 0 };//不能重复入队

//每个节点需要记录 节点位置x 和 走的步数steps
struct Step{
    int x;
    int steps;
    Step(int _x, int _stp):x(_x),steps(_stp) { }
};

queue<Step> q; //Open表，本题不用维护Close表

int main()
{
    cin >> N >> K;
    q.push(Step(N,0));
    visited[N] = 1;
    
    while(!q.empty())
    {
        Step s = q.front();
        if(s.x == K){
            cout << s.steps << endl;
            return 0;
        }
        else
        {
            if(s.x - 1 >= 0 && !visited[s.x - 1]){
                q.push(Step(s.x - 1, s.steps + 1));
                visited[s.x - 1] = 1;
            }
            if(s.x + 1 <= MAXN && !visited[s.x + 1]){
                q.push(Step(s.x + 1, s.steps + 1));
                visited[s.x + 1] = 1;
            }
            if(s.x * 2 <= MAXN && !visited[s.x * 2]){
                q.push(Step(s.x * 2, s.steps + 1));
                visited[s.x * 2] = 1;
            }
            q.pop();
        }
    }
    return 0;
}
