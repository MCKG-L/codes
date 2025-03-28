/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number between 0 and 1000: ";
    cin >> n;
    int ans = 0;
    while(n){
        ans += n%10;
        n /= 10;
    }
    cout << "The sum of the digit is " << ans << endl;
    return 0;
}