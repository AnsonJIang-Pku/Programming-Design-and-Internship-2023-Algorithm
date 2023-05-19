#include <iostream>
#include <cstring>
using namespace std;

char Left[3][7]; //如果写成char Left[3];代表一个字符串，有三位。否则应该写成char* Left[3];
char Right[3][7];
char Result[3][7];
bool IsFake(char c, bool light);

bool IsFake(char c, bool light)
{
    char * pLeft, * pRight;
    //注意定义的写法 char *pLeft, pRight;定义出来的pRight是char类型
    //利用strchr(char* , char )来找一段字符串中是否含有某个字符
    for(int i = 0; i < 3; i++)
    {
        if(light)
        {
            pLeft = Left[i];
            pRight = Right[i];
        }
        else
        {
            pLeft = Right[i];
            pRight = Left[i];
        }
        
        switch(Result[i][0])
        {
            case 'u':
                if(strchr(pRight,c) == NULL)
                    return false;
                break;
            case 'e':
                if(strchr(pLeft,c) || strchr(pRight,c))
                    return false;
                break;
            case 'd':
                if(strchr(pLeft,c) == NULL)
                    return false;
                break;
        }
    }
    return true;
    
}

int main()
{
    int n; //数据组数
    cin >> n;
    while(n--)
    {
        for(int i = 0; i < 3; i++)
            cin >> Left[i] >> Right[i] >> Result[i];
        for(char c = 'A'; c <= 'L'; c++) //对所有硬币枚举
        {
            if(IsFake(c, true)) //假设c是假的，且c是轻的
            {
                cout << c << " is the counterfeit coin and it is light." << endl;
            }
            else if(IsFake(c,false))
            {
                cout << c << " is the counterfeit coin and it is heavy. " << endl;
            }
        }
    }
    return 0;
}
