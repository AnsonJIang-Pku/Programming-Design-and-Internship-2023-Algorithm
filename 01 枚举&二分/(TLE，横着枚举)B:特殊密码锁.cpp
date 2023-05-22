#include <iostream>
#include <math.h>
#include <string>
//注意超时问题；位运算的熟练，改变原值要加引用，math.h中的pow
using namespace std;

string s1,s2;
int o,t; //original, target
int len; //string串长度
int cnt; //存储操作数

//位运算函数
//反转二进制数x的第j位
inline void Flip(int &x, int j)//一开始没加引用！什么也没改
{
    x ^= (1 << j);
}

//得到二进制数x的第j位
inline int GetBit(int x, int j)
{
    return (x >> j) & 1;
}

//将string对象转换为int
inline int Convert(string st)
{
    int res = 0;
    for(int i = 0; i < len; i++)
        res += (st[i]-'0') * pow(2, i); //将string对象转换为2进制数加和
    return res;
}

void Solve()
{
    int temp;//存储枚举的中间结果
    bool flag = 1;
    //对于“操作”枚举：0-(2^len)-1种操作
    for (int n = 0; n < pow(2,len); n++)//这一步操作超时了
    {
        temp = o; //初始化中间变量为original
        cnt = 0; //从零开始计数
        for(int j = 0; j < len; j++)
        {
            if(GetBit(n, j)) //”操作“n的第j位为1，则Flip相邻的位
            {
                cnt++;
                Flip(temp, j); //改变temp（或者o）的第j位
                if(j != 0)
                {
                    Flip(temp,j-1);//如果j不在左边界，改变前一位
                }
                if(j != len-1)
                {
                    Flip(temp, j+1);//如果j不在右边界，改变后一位
                }
            }
        }
        if(temp == t)//找到结果
        {
            cout << cnt << endl;
            flag = 0;
        }
    }
    if (flag)
        cout << "impossible" << endl;
}

int main()
{
    cin >> s1 >> s2;
    //每个密码最多30位，因此可以用int(32bits)存
    len = s1.length();
    //将s1和s2转换为两个int类型数
    o = Convert(s1); t = Convert(s2);
    Solve();
    return 0;
}
