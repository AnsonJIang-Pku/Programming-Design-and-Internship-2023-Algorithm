//不能处理带空格的表达式
//不能判断除以0出错
#include <iostream>
#include <algorithm>
using namespace std;

int expression_value();
int factor_value();
int term_value();

int expression_value()
{
    int res = term_value(); //下一层的值
    while(true)
    {
        char op = cin.peek();
        if(op == '+' || op == '-')
        {
            cin.get();
            int value = term_value();
            if(op == '+')
                res += value;
            else
                res -= value;
        }
        else
            break;
    }
    return res;
}

int term_value()
{
    int res = factor_value(); //下一层的值
    while (true) {
        char op = cin.peek();
        if(op == '*' || op == '/')
        {
            cin.get();
            int value = factor_value();
            if(op == '*')
                res *= value;
            else
                res /= value;
        }
        else
            break;
    }
    return res;
}

int factor_value()
{
    int res = 0; //递归出口不能再调用exp_val()了，因为可能直接是整数，跳出递归
    char c = cin.peek();
    if(c == '(')
    {
        cin.get();
        res = expression_value(); //这里才是exp_val()
        cin.get(); //读取出右括号
    }
    else{
        while(isdigit(c))
        {
            res = 10 * res + c - '0';
            cin.get();
            c = cin.peek();
        }
    }
    return res;
}
int main()
{
    cout << expression_value() << endl;
    return 0;
}
