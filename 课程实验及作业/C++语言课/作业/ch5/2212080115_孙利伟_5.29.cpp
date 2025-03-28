/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int cnt = 0;
    for(int i=2001;i<=2100;i++){
        if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0){
            cout << i << ' ';cnt ++;
            if(cnt % 10 == 0) cout << endl;
        }
    }
    return 0;
}