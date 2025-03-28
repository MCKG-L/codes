#include <bits/stdc++.h>
using namespace std;
/*
给定一个字符串str，在其后加上一个字符串使得整体变成回文字符串
问：加上的最短字符串的长度是多大？
*/
/*
解法：从左往右，找到第一个以最后一个字符为结尾的回文串，长度为Max,相应的处理前的
对应长度为Max - 1
*/
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
    int Max = -1;
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
        if(R == str.size()){
            Max = pArr[i];
            break;
        }
    }
    return s.size() - Max + 1;
}
int main()
{
    string s;
    cin >> s;
    cout << manacher(s);
    return 0;
}