#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;
unordered_map<char,int> mp = {{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},
{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}};
void func(int x,int m){
    if(x == 0) return;
    func(x/m,m);
    int r = x % m;
    if(r < 10) cout << r;
    else if(r >= 10){
        cout << (char)('A' + r - 10);
    }
}
int main()
{
    int n;cin >> n;
    string s;cin >> s;
    int x = 0,l = s.size();
    for(int i=0;i<l;i++){
        x += pow(n,l-i-1)*mp[s[i]];
    }
    // cout << x;
    int m;cin >> m;
    func(x,m);
    return 0;
}