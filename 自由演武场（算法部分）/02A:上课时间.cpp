//有点“尝试性”技巧的枚举题
//注意重载函数的const声明位置
#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct Cls{
    int a,b;
    bool operator<(Cls cl)const{
        return a < cl.a;
    }
};
Cls classes[1010];
int res;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> classes[i].a >> classes[i].b;
    sort(classes,classes + n);
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++){
            if(classes[i].b < classes[j].a)
                continue;
            res = max(res, min(classes[i].b, classes[j].b) - classes[j].a + 1);
        }
    }
    cout << res << endl;
    return 0;
}
