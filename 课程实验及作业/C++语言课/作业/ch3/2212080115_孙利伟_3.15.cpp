/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unordered_map>
using namespace std;
unordered_map<int,string> mp{{0,"scissor"},{1,"rock"},{2,"paper"}};
int main()
{
    srand(time(0));
    int mask = rand() % 3;
    int ans;
    cout << "scissor(0), rock(1), paper(2): ";
    cin >> ans;
    if(ans == mask)cout << "The computer is " << mp[mask] << ". You are " << mp[ans] << " too. It is a draw\n";
    else if(ans != 0 && mask != 0){
        cout << "The computer is " << mp[mask] << ". You are " << mp[ans] << ". ";
        if(ans > mask) cout << "You won" << endl;
        else cout << "You lose" << endl;
    }else{
        cout << "The computer is " << mp[mask] << ". You are " << mp[ans] << ". ";
        if(mask == 0){
            if(ans == 1) cout << "You won" << endl;
            else cout << "You lose" << endl;
        }
        else if(ans == 0){
            if(mask == 1) cout << "You lose" << endl;
            else cout << "You won" << endl;
        }
    }
    return 0;
}