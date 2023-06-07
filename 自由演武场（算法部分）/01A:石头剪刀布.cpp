#简单枚举
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N, NA, NB;
    int ra = 0, rb = 0;
    cin >> N >> NA >> NB;
    int *a = new int[NA+1];
    int *b = new int[NB+1];
    for(int i = 0; i < NA; i++)
        cin >> a[i];
    for(int i = 0; i < NB; i++)
        cin >> b[i];
    //enumerate
    for(int i = 0; i < N; i++)
    {
        if(a[i % NA] == 0 && b[i % NB] == 5)
            rb++;
        if(a[i % NA] == 5 && b[i % NB] == 0)
            ra++;
        if(a[i % NA] == 2 && b[i % NB] == 5)
            ra++;
        if(a[i % NA] == 5 && b[i % NB] == 2)
            rb++;
        if(a[i % NA] == 0 && b[i % NB] == 2)
            ra++;
        if(a[i % NA] == 2 && b[i % NB] == 0)
            rb++;
    }
    if(ra == rb)
        cout << "draw" << endl;
    else if(ra < rb)
        cout << "B" << endl;
    else
        cout << "A" << endl;
    return 0;
}
