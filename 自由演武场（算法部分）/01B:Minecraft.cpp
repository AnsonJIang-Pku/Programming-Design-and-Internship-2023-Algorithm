//简单的枚举
#include <iostream>
#include <string>
//注意摆放的结果也是长方体！不是任意形状
using namespace std;

int main()
{
    int N,a,b,c;
    cin >> N;
    int min = 6 * N;
    for(a = 1; a <= N; a++){
        for(b = 1; b <= N; b++){
            c = N / (a * b); //c被迫转换为整数
            if(a * b * c == N) //保证abc均为整数的前提下满足要求
                if(2 * (a*b + a*c + b*c) < min)
                    min = 2 * (a*b + a*c + b*c);
        }
    }
    cout << min << endl;
    return 0;
}
