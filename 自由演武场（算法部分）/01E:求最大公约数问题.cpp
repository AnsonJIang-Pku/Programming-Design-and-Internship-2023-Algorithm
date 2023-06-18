//知道辗转相除法的原理 gcd(a,b) = gcd(b,a%b) (a > b > 0)就好做了
//swap()在algorithm中
#include <iostream>
#include <algorithm>
using namespace std;

//Gcd: Greatest Common Divisor
int Gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    else
        return Gcd(b, a % b);
}

int main()
{
    int a,b;
    cin >> a >> b;
    if(a < b)
        swap(a,b);
    cout << Gcd(a,b) << endl;
    return 0;
}
