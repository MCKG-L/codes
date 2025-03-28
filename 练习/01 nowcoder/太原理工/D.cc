#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
vector<int>a,b,c;
bool cmp(int a,int b){
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;cin >> s;
    for(int i=0;i<s.size();i++) c.push_back(s[i]-'0');
    sort(c.begin(),c.end(),cmp);
    int n = c.size();
    int mask = 1;
    for(int i=0;i<n;i++){
        if(mask) a.push_back(c[i]);
        else b.push_back(c[i]);
        mask ^= 1;
    }
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);
    while(a.size()>1 && a.front() == 0) a.pop_back();
    while(b.size()>1 && b.front() == 0) b.pop_back();
    for(int i=0;i<a.size();i++) cout << a[i];cout << endl;
    for(int i=0;i<b.size();i++) cout << b[i];cout << endl;
    return 0;
}