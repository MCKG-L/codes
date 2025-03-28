/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double e = 1.0,k = 1.0;
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        k /= i;
        e += k;
    }
    cout << e << endl;
    return 0;
}