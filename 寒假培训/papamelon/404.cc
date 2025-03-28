#include <bits/stdc++.h>
using namespace std;
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