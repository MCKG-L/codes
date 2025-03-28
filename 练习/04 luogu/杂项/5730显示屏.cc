#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;cin >> n;
    string s;
    string ans[5];
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] == '0'){
            ans[0] += "XXX";
            ans[1] += "X.X";
            ans[2] += "X.X";
            ans[3] += "X.X";
            ans[4] += "XXX";
        }
        if(s[i] == '1'){
            ans[0] += "..X";
            ans[1] += "..X";
            ans[2] += "..X";
            ans[3] += "..X";
            ans[4] += "..X";
        }
        if(s[i] == '2'){
            ans[0] += "XXX";
            ans[1] += "..X";
            ans[2] += "XXX";
            ans[3] += "X..";
            ans[4] += "XXX";
        }
        if(s[i] == '3'){
            ans[0] += "XXX";
            ans[1] += "..X";
            ans[2] += "XXX";
            ans[3] += "..X";
            ans[4] += "XXX";
        }
        if(s[i] == '4'){
            ans[0] += "X.X";
            ans[1] += "X.X";
            ans[2] += "XXX";
            ans[3] += "..X";
            ans[4] += "..X";
        }
        if(s[i] == '5'){
            ans[0] += "XXX";
            ans[1] += "X..";
            ans[2] += "XXX";
            ans[3] += "..X";
            ans[4] += "XXX";
        }
        if(s[i] == '6'){
            ans[0] += "XXX";
            ans[1] += "X..";
            ans[2] += "XXX";
            ans[3] += "X.X";
            ans[4] += "XXX";
        }
        if(s[i] == '7'){
            ans[0] += "XXX";
            ans[1] += "..X";
            ans[2] += "..X";
            ans[3] += "..X";
            ans[4] += "..X";
        }
        if(s[i] == '8'){
            ans[0] += "XXX";
            ans[1] += "X.X";
            ans[2] += "XXX";
            ans[3] += "X.X";
            ans[4] += "XXX";
        }
        if(s[i] == '9'){
            ans[0] += "XXX";
            ans[1] += "X.X";
            ans[2] += "XXX";
            ans[3] += "..X";
            ans[4] += "XXX";
        }
        if(i != s.size()-1){
            for(int j=0;j<5;j++){
                ans[j] += ".";
            }
        }
    }
    for(int i=0;i<5;i++){
        cout << ans[i] << "\n\0"[i == 4];
    }
    return 0;
}