/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    for(int i=1;i<=6;i++){
        for(int j=1;j<=i;j++) cout << j << ' ';
        cout << endl;
    }
    cout << endl;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6-i+1;j++) cout << j << ' ';
        cout << endl;
    }
    cout << endl;
    for(int i=1;i<=6;i++){
        for(int j=i;j>=1;j--) cout << j << ' ';
        cout << endl;
    }
    cout << endl;
    for(int i=1;i<=6;i++){
        for(int j=6-i+1;j>=1;j--) cout << j << ' ';
        cout << endl;
    }
    cout << endl;
    return 0;
}