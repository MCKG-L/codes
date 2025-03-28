/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    char c;int ans = 0;
    cout << "Enter a letter: ";cin >> c;
    if(c >= 'A' && c <= 'Z') c += 32;
    if(c >= 'a' && c <= 'z'){
        if(c == 'a' || c == 'b' || c == 'c') ans = 2;
        else if(c == 'd' || c == 'e' || c == 'f') ans = 3;
        else if(c == 'g' || c == 'h' || c == 'i') ans = 4;
        else if(c == 'j' || c == 'k' || c == 'l') ans = 5;
        else if(c == 'm' || c == 'n' || c == 'o') ans = 6;
        else if(c == 'p' || c == 'q' || c == 'r' || c == 's') ans = 7;
        else if(c == 't' || c == 'u' || c == 'v') ans = 8;
        else if(c == 'w' || c == 'x' || c == 'y' || c == 'z') ans = 9;
        cout << "The corresponding number is " << ans << endl;
    }else cout << c << " is an unvalid input" << endl;
    return 0;
}
