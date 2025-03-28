/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<char,string> mp{{'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},{'4',"0100"},{'5',"0101"},{'6',"0110"},
{'7',"0111"},{'8',"1000"},{'9',"1001"},{'A',"1010"},{'B',"1011"},{'C',"1100"},{'D',"1101"},{'E',"1110"},{'F',"1111"}};
int main()
{
    string s,ans;
    cout << "Enter a hex digit: ";
    cin >> s;
    for(char i : s){
        ans += mp[i];
    }
    reverse(ans.begin(),ans.end());
    while(ans.back() == '0' && ans.size() > 1) ans.pop_back();
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}