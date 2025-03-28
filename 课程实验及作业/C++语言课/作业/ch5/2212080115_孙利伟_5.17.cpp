/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    char c = '!';
    int cnt = 0;
    while(c != '~'){
        cout << c << ' ';
        cnt ++;c ++;
        if(cnt % 10 == 0) cout << endl;
    }
    cout << c;
    return 0;
}