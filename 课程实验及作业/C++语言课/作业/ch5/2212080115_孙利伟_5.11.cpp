/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10010;
pair<int,string> p[N];
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> p[i].second >> p[i].first;
    }
    sort(p,p+n);
    cout << p[n-1].second << " " << p[n-1].first << endl;
    cout << p[n-2].second << " " << p[n-2].first << endl;
    return 0;
}