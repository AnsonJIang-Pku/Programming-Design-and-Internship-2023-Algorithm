//简单的双向最长子序列
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

//多组数据：注意每次任务执行后，清除已有的数据
int K, N;
vector<int> h;
int dpl[110],dpr[110]; //可以从两个方向看最长子序列

int main()
{
    cin >> K;
    while(K)
    {
        cin >> N;
        memset(dpl,0,sizeof(dpl)); //清除数据
        memset(dpr,0,sizeof(dpr));
        for(int i = 0; i < N; i++){
            int tmp;
            cin >> tmp;
            h.push_back(tmp);
            dpl[i] = dpr[i] = 1;
        }
        //从左边开始建立dp,经典的最长子列问题
        for(int i = 1; i < N; i++){
            for(int j = 0; j < i; j++){
                if(h[j] < h[i])
                    dpl[i] = max(dpl[i], dpl[j] + 1);
            }
        }
        //从右边开始建立dp，先reverse转化为从左开始的问题
        reverse(h.begin(),h.end());
        for(int i = 1; i < N; i++){
            for(int j = 0; j < i; j++){
                if(h[j] < h[i])
                    dpr[i] = max(dpr[i], dpr[j] + 1);
            }
        }
        cout << max(*max_element(dpl, dpl + N), *max_element(dpr, dpr + N)) << endl;
        h.clear();  //清除数据
        K--;
    }
    return 0;
}
