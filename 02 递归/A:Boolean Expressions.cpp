//如何区分优先级？将表达式分为不同的层次：&|为外层，!()VF为内层
//要区分&的优先级高于|的优先级，需要再引入一层
// 注意(V | F & F) 与表达式 ((V|F) & F)不等价，实际结果应该是V
//本程序是完全正确的
#include <iostream>
using namespace std;

bool expression_value();
bool term_value();
bool factor_value();

bool expression_value()
{
    bool res = term_value();
    while(true)
    {
        char op = cin.peek();
        if(op == '|'){
            cin.get();
            bool val = term_value();
            res |= val;
        }
        else if(op == ' ') //在这里吃后空格
            cin.get();
        else
            break;
    }
    return res;
}

bool term_value()
{
    bool res = factor_value();
    while(true)
    {
        char op = cin.peek();
        if(op == '&'){
            cin.get();
            bool val = factor_value();
            res &= val;
        }
        else if(op == ' ') //在这里吃后空格
            cin.get();
        else
            break;
    }
    return res;
}

bool factor_value()
{
    char op = cin.peek();
    while(op == ' '){
        cin.get();
        op = cin.peek();
    }
    if(op == 'V'){
        cin.get();
        return true;
    }
    else if(op == 'F'){
        cin.get();
        return false;
    }
    else if(op == '!'){
        cin.get();
        return !factor_value();
    }
    else if(op == '(')
    {
        cin.get();
        bool res = expression_value();
        cin.get();
        return res;
    }
    return false; //这里在Xcode里必须写一个值，实际上不会遇到
}

int main()
{
    int cnt = 1;
    while(cin.peek() != EOF){
        cout << "Expression " << cnt << ": ";
        cnt++;
        if(expression_value())
            cout << "V" << endl;
        else
            cout << "F" << endl;
        cin.get(); //Star: 把回车吃掉，否则会进入无限循环
    }
    return 0;
}
