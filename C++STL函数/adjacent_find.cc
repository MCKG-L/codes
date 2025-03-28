#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、在头文件 algorithm 中
2、查找相等且连续的元素
3、返回值：如果找到则返回指向满足条件的第一个元素的迭代器，如果不存在，则返回尾迭代器
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n){
        vector<int> a(n);
        for(int &i : a) cin >> i;
        auto it = adjacent_find(a.begin(),a.end());
        if(it == a.end()){
            cout << -1 << endl;
        }else{
            cout << it-a.begin() << ' ' << it-a.begin()+1 << endl;
        }
    }
    return 0;
}