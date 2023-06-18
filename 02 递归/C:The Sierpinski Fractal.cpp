//Presentation Error：答案和标准答案很接近，但是有格式错误
//拆分问题的方法，设置递归参数的思路：左下角的坐标！
#include <iostream>
#include <algorithm>
using namespace std;
//左移运算符<<的优先级比四则运算小
//反斜杠被定义为转义字符，想要输出需要'\\'

int n;
char a[5000][5000];

//不能出现trailing blanks(虽然oj并没有检测这个)
void Ini()
{
    for(int i = 0; i < (1 << 11); i++)
        for(int j = 0; j < (1 << 12); j++)
            a[i][j] = ' ';
    return ;
}

//(x,y)为待绘制三角形的左下顶点坐标; m为递归深度
void Tri(int x, int y, int m)
{
    //确定递归出口
    if(m == 1){
        a[x][y] = '/';
        a[x-1][y+1] = '/'; a[x-1][y+2] = '\\';
        a[x][y+1] = '_'; a[x][y+2] = '_'; a[x][y+3] = '\\';
        return ;
    }
    int h = 1 << m, w = 1 << (m+1);
    Tri(x, y, m - 1);
    Tri(x - h/2, y + w/4, m - 1);
    Tri(x, y + w/2, m - 1);
    return ;
}

void Print()
{
    for(int i = 1; i <= (1<<n); i++){
        for(int j = 0; j <= (1 << (n+1)); j++)
            cout << a[i][j];
        cout << endl;
    }
    return;
}

int main()
{
    while(cin >> n && n != 0)
    {
        Ini();
        Tri(1 << n, 0, n);
        Print();
        cout << endl; //Print an empty line after each test case.
    }
    return 0;
}
