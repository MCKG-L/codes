#include <bits/stdc++.h>
using namespace std;
//使用count函数 按照指定值计数
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n,m,k;
//     while(cin >> n){
//         vector<int> a(n);
//         cin >> m >> k;
//         for(int &i : a){
//             cin >> i;
//             i = fabs(i-m) <= k;
//         }
//         cout << count(a.begin(),a.end(),1);
//     }
//     return 0;
// }
//使用count_if函数 按照条件奇计数
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