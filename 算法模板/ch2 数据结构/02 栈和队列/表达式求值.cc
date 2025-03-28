#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;
/*
利用栈结构，将中缀表达式转化为后缀表达式
*/
//双栈
stack<int>num;
stack<char>op;

//求值函数,使用末尾的运算符操作末尾的两个数
void eval()
{
    auto b = num.top(); num.pop();//第二个操作数
    auto a = num.top(); num.pop();//第一个操作数
    auto c = op.top(); op.pop();  //运算符

    int x;                        //结果计算(注意顺序)
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;
    num.push(x);                  //结果入栈
}

int main()
{
    //优先级表
    unordered_map<char, int>pr{ {'+',1},{'-',1},{'*',2},{'/',2} };

    //读入表达式
    string str;
    cin >> str;

    //从前往后扫描表达式
    for (int i = 0; i < str.size(); i++)
    {
        auto c = str[i];
        //扫描到数字,使用双指针法一直读入
        if (isdigit(c))
        {
            //j表示扫描到数字的指针
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0';
            //更新i指针
            i = j - 1;
            //数字入栈
            num.push(x);
        }
        //左括号直接入栈
        else if (c == '(')op.push(c);
        //右括号出现,从右往左计算栈中数据,直到遇见左括号
        else if (c == ')')
        {
            //不断使用eval函数对末尾数字运算
            while (op.top() != '(')eval();
            //弹出左括号
            op.pop();
        }
        //扫描到运算符
        else
        {
            //如果栈顶运算符优先级较高,先操作栈顶元素再入栈
            while (op.size() && pr[op.top()] >= pr[c]) eval();
            //如果栈顶运算符优先级较低,直接入栈
            op.push(c);
        }
    }
    //把没有操作完的运算符从右往左操作一遍
    while (op.size()) eval();
    //栈顶元素为最终答案
    cout << num.top() << endl;
    return 0;
}
