#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    string s = "accs";
    s += "dss";

    //substr
    cout << s << endl;
    cout << s.substr(1,2) << endl;//第二个参数是长度
    cout << s.substr(1) << endl;

    //c_str 返回string存储字符串的起始地址
    printf("%s",s.c_str());
    return 0;
}