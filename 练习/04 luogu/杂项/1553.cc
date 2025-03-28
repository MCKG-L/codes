#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool is_digit(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] <'0' || s[i] > '9') return false;
    }
    return true;
}
bool is_xiaoshu(string s){
    for(char i : s){
        if(i == '.') return true;
    }
    return false;
}
bool is_fenshu(string s){
    for(char i : s){
        if(i == '/') return true;
    }
    return false;
}
bool is_baifenshu(string s){
    if(s.back() == '%') return true;
    else return false;
}
string m_reverse(string s){
    while(s.back() == '0' && s.size() > 1) s.pop_back();
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    string s;cin >> s;
    if(is_digit(s)){
        cout << m_reverse(s) << endl;
    }else if(is_xiaoshu(s)){
        int pos = s.find('.');
        // cout << pos;
        string s1 = s.substr(0,pos);
        string s2 = s.substr(pos+1);
        s2 = m_reverse(s2);
        while(s2.back()=='0'&&s2.size()>1) s2.pop_back();
        // cout << s1 << '.' << s2;
        cout << m_reverse(s1) << '.' << s2 << endl;
    }else if(is_fenshu(s)){
        int pos = s.find('/');
        string s1 = s.substr(0,pos);
        string s2 = s.substr(pos+1);
        cout << m_reverse(s1) << '/' << m_reverse(s2) << endl;
    }else if(is_baifenshu(s)){
        s.pop_back();
        cout << m_reverse(s) << '%' << endl;
    }
    return 0;
}