#include <bits/stdc++.h>
using namespace std;
/*
    字符串转化
    有26种对应关系 1->A 2->B 3->C ..... 11->K ... 26->Z
    给定一个数字字符串如"111",可以转化为"AAA" "KA" "AK"；
    给定一个数字字符串（0~9组成），问有多少种转化结果？

*/
string s;
int mp[100];
int process(int index){
    if(mp[index]!=-1) return mp[index];

    int ans = 0;
    if(index == s.size()) ans = 1;
    else if(s[index] == '0') ans = 0;
    else{
        ans = process(index+1);
        if((s[index]-'0')*10+s[index+1]-'0' < 27 && index + 1 < s.size()){
            ans += process(index+2);
        }
    }
    mp[index] = ans;
    return ans;

    // if(index == s.size()){
    //     return 1;
    // }
    // if(s[index] == '0') return 0;
    // int ans = process(index+1);//单转
    // if((s[index]-'0')*10+(s[index+1]-'0') < 27 && index+1 < s.size()){
    //     ans += process(index+2);
    // }//判断是否可以和下一个字符组合转
    // return ans;
}
int solve(){
    return process(0);
}
int main()
{
    cin >> s;
    for(int i=0;i<=s.size();i++){
        mp[i] = -1;
    }
    cout << solve();
}