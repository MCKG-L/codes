#include <bits/stdc++.h>
using namespace std;
/*
1、在头文件 algorithm 中
2、四个参数，前两个参数指明范围，第三个参数是保存位置，第四个参数是操作函数
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,ans;
    cin >> s;
    ans.resize(s.size());
    transform(s.begin(),s.end(),s.begin(),[&](char c){return (c>='a'&&c<='z'?c-=32:c);});
    cout << s;
    system("pause");
    return 0;
}