/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Enter a letter: ";cin >> ch;
    if(ch == 'a'|| ch == 'A' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u'){
        cout << ch << " is a vowel" << endl;

    }else cout << ch << " is a consonant" << endl;
    return 0;
}