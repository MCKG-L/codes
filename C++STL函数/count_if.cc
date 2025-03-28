#include <bits/stdc++.h>
using namespace std;
//使用count函数 按照指定值计数
//使用count_if函数 按照条件计数
/*
1、count_if的第三个参数时谓词（pred）即bool类型的函数
2、可以是lambda表达式的形式，也可以自己写函数
*/
int main()
{
    int n,m,k;
    while(cin >> n){
        vector<int> a(n);
        cin >> m >> k;
        for(int &i : a){
            cin >> i;
        }
        cout << count_if(a.begin(),a.end(),[&](int &x){return fabs(x-m)<=k;});
    
    }
    return 0;
}