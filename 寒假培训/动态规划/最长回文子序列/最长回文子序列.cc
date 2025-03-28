#include <bits/stdc++.h>
using namespace std;
/*
求str的最长回文子序列可以转化为求 str和逆str的最长公共子序列

现用另外一种思路做 范围尝试模型--> 普遍情况要讨论两端要还是不要
*/
string s;
//返回l 到 r 范围的最长回文子序列
int process(int l,int r){
    //basecase
    if(l == r) return 1;
    if(l + 1 == r) return s[l] == s[r] ? 2 : 1;

    int p1 = process(l+1,r-1);
    int p2 = process(l+1,r);
    int p3 = process(l,r-1);
    int p4 = s[l] == s[r] ? (2 + process(l+1,r-1)) : 0;
    return max(max(p1,p2),max(p3,p4));
}
int solve(){
    int N = s.size();
    return process(0,N-1);
}
int main()
{
    cin >> s;
    cout << solve();
    return 0;
}