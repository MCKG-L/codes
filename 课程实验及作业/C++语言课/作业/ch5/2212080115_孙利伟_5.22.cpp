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
    for(int i=2;i<=1000;i++){
        int mask = true;
        for(int j=2;j<=i/j;j++){
            if(j % i == 0){
                mask = false;
                break;
            }
        }
        if(mask){
            cnt ++;
            cout << i << ' ';
            if(cnt % 8 == 0) cout << endl;
        }
    }
    return 0;
}