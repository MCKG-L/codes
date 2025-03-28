#include <bits/stdc++.h>
using namespace std;
/*
给定两个字符串str1,str2
str1: "a12bc345def"
str2: "mnp123qrs45z"

最长公共子序列和为："12345" 返回5
*/
//样本对应模型
/* 尝试模型
1、从左到右尝试模型
2、范围尝试模型
3、样本对应模型
*/

//暴力递归，做题可能会超时
string s1,s2;
int process(int i,int j){
    //求str1[0....i]和str2[0....j]的最大公共子序列和

    //base-case
    if(j == 0 && i == 0){
        return s1[i] == s2[j] ? 1 : 0;
    }else if(i == 0){
        return s1[i] == s2[j] ? 1 : process(i,j-1);
    }else if(j == 0){
        return s1[i] == s2[j] ? 1 : process(i-1,j);
    }else{
        int p1 = process(i-1,j);//最长子序列不以s1[i]结尾，但是可能以s2[j]结尾
        int p2 = process(i,j-1);//最长子序列不以s2[j]结尾，但是可能以s1[i]结尾
        int p3 = s1[i] == s2[j] ? (1 + process(i-1,j-1)) : 0;//最长子序列以s1[i]和s2[j]结尾
        return max(max(p1,p2),p3);
    }
}
int solve(){
    //尝试
    return process(s1.size()-1,s2.size()-1);
}

int main()
{
    cin >> s1 >> s2;
    cout << solve();
    return 0;
}