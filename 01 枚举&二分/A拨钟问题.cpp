#include <iostream>
//适当选取循环条件<分析问题>
using namespace std;
int main()
{
    //a[]代表初始状态；op[i]代表第i个操作的次数
    int a[10] = { 0 }, op[10] = { 0 };
    for(int i = 1; i <= 9; i++)
        cin >> a[i];
    //第一种操作可以执行0-3次，以此类推
    for(op[1] = 0; op[1] <= 3; op[1]++)
    {
        for(op[2] = 0; op[2] <= 3; op[2]++)
        {
            for(op[3] = 0; op[3] <= 3; op[3]++)
            {
                for(op[4] = 0; op[4] <= 3; op[4]++)
                {
                    for(op[5] = 0; op[5] <= 3; op[5]++)
                    {
                        for(op[6] = 0; op[6] <= 3; op[6]++)
                        {
                            for(op[7] = 0; op[7] <= 3; op[7]++)
                            {
                                for(op[8] = 0; op[8] <= 3; op[8]++)
                                {
                                    for(op[9] = 0; op[9] <= 3; op[9]++){
                                        if(
                                    (a[1] + op[1] + op[2] + op[4]) % 4 == 0 &&
                            (a[2] + op[1] + op[2] + op[3] + op[5]) % 4 == 0 &&
                                    (a[3] + op[2] + op[3] + op[6]) % 4 == 0 &&
                            (a[4] + op[1] + op[4] + op[5] + op[7]) % 4 == 0 &&
                    (a[5] + op[1] + op[3] + op[5] + op[7] + op[9]) % 4 == 0 &&
                            (a[6] + op[3] + op[5] + op[6] + op[9]) % 4 == 0 &&
                                (a[7] + op[4] + op[7] + op[8]) % 4 == 0 &&
                            (a[8] + op[5] + op[7] + op[8] + op[9]) % 4 == 0 &&
                                (a[9] + op[6] + op[8] + op[9]) % 4 == 0
                                    )
                                        {
                                            for (int i = 1; i <= 9; i++)
                                            {
                                                if(op[i] != 0)
                                                {
                                                    for(int j = 1; j <= op[i]; j++)
                                                        cout << i << ' ';
                                                }
                                            }
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
        
    return 0;
}

