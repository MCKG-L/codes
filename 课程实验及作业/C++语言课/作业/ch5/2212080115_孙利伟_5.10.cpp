/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
const int N = 100010;
pair<int,string> p[N];
int main()
{
    int n;cin >> n;
    int res = 0,max_ = 0;
    for(int i=0;i<n;i++){
        string name;int x;
        cin >> name >> x;
        p[i] = make_pair(x,name);
        if(x > max_) res = i,max_ = x;
    }
    cout << p[res].second << endl;
    return 0;
}