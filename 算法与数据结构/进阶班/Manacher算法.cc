#include <bits/stdc++.h>
using namespace std;
// manacher算法 时间复杂度为O(N)
string manacherString(string s){
    int n = s.size();
    string ans;
    ans.resize(2 * n + 1);
    for(int i=0;i<2*n+1;i++){
        ans[i] = i % 2 == 0 ? '#' : s[i/2];
    }
    return ans;
}
int manacher(string s){
    if(s.size() == 0) return 0;
    //处理原字符串
    string str = manacherString(s);
    //回文范围 [L,R)
    int N = str.size();
    int pArr[N];//回文半径
    int C = -1,R = -1;//C为回文半径 R为最右回文边界加1
    int ans = INT_MIN;
    for(int i=0;i<N;i++){
        //记录不用验的最小区域长度
        pArr[i] = R > i ? min(pArr[2 * C - i],R - i) : 1;
        //验证
        while(i + pArr[i] < str.size() && i - pArr[i] > -1){
            if(str[i + pArr[i]] == str[i - pArr[i]]){
                pArr[i]++;
            }else{
                break;
            }
        }    
        //更新
        if(i + pArr[i] > R){
            R = i + pArr[i];
            C = i;
        }
        ans = max(ans,pArr[i]);
    }
    return ans - 1;

}
int main()
{
    string s;
    cin >> s;
    cout << manacher(s);
    return 0;
}