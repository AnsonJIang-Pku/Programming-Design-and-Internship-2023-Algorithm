//参考了 https://blog.csdn.net/m0_46283220/article/details/112754809
//注意构建单项影响的算法

#include <iostream>
#include <math.h>
#include <string>
//注意超时问题；位运算的熟练，改变原值要加引用，math.h中的pow
using namespace std;

string s1,s2;
int o,t; //original, target
int cnt = 0; //存储操作数
int len;

//位运算函数
//反转二进制数x的第j位
void Flip(int &x, int j)//一开始没加引用！什么也没改
{
    x ^= (1 << j);
}
//得到二进制数x的第j位
int GetBit(int x, int j)
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
    int temp1 = o,temp2 = o;//存储中间的反转结果
    int cnt1 = 0, cnt2 = 0;
    //由于第0位是一个局部，考虑第0位反转与否两种情况
    //case1:反转第0位
    cnt1++;
    Flip(temp1,0);
    if(len >= 2)
        Flip(temp1,1);
    for(int i = 0; i < len; i++)
    {
        int a1 = GetBit(temp1, i);
        int a2 = GetBit(t, i);
        if(a1 != a2)
        {
            cnt1++;
            Flip(temp1,i);
            Flip(temp1,i+1);
            if(i < len - 2)
                Flip(temp1,i+2);//相当于按下了i+1的钮
        }
    }
    //case2:不反转第0位
    for(int i = 0; i < len; i++)//仅对len>=3的有效
    {
        if(GetBit(temp2, i) != GetBit(t, i))
        {
            cnt2++;
            Flip(temp2,i);
            Flip(temp2,i+1);
            if(i < len - 2)
                Flip(temp2,i+2);//相当于按下了i+1的钮
        }
    }
    
    if(temp1 == t)
        cout << cnt1 << endl;
    else if(temp2 == t)
        cout << cnt2 << endl;
    else
        cout << "impossible" << endl;
}

int main()
{
    cin >> s1 >> s2;
    //每个密码最多30位，因此可以用int(32bits)存
    len = s1.length();
    //将s1和s2转换为两个int类型数
    o = Convert(s1); t = Convert(s2);
    //cout << GetBit(7, 2) <<' '<<GetBit(4, 2);
    Solve();
    return 0;
}
