#include <bits/stdc++.h>
using namespace std;
/*
1、count函数在头文件 algorithm 中
2、count函数时按值计数，前两个参数指明范围，第三个参数时参考数值，即统计该数值在范围内出现的次数
3、可以用在string类型中查找字符
    string s;
    cin >> s;
    int n = count(s.begin(),s.end(),'m');
    cout << n;
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin >> n){
        vector<int> a(n);
        for(int &i : a){
            cin >> i;
        }
        cin >> m;
        cout << count(a.begin(),a.end(),m);
    }
    return 0;

}