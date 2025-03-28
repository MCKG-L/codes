/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    string s,t;
    cout << "Enter a SSN: ";cin >> s;
    t = s;
    int pos = s.find('-');
    if(pos == s.size()){
        cout << s << "is an invalid social security number" << endl;
        return 0;
    }
    string b = s.substr(0,pos);
    if(b.size() != 3){
        cout << s << " is an invalid social security number" << endl;
        return 0;
    }
    s = s.substr(pos+1);
    pos = s.find('-');
    if(pos == s.size()){
        cout << s << " is an invalid social security number" << endl;
        return 0;
    }
    b = s.substr(0,pos);
    if(b.size()!=2){
        cout << s << " is an invalid social security number" << endl;
        return 0;
    }
    s = s.substr(pos+1);
    if(s.size() != 4){
        cout << s << " is an invalid social security number" << endl;
        return 0; 
    }
    cout << t << " is a valid social security number" << endl;
    return 0;
}