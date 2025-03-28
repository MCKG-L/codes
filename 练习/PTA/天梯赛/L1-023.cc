#include <iostream>
using namespace std;
const int N = 10005;
int g,p,l,t;
int main()
{
    string s;cin >> s;
    for(auto i : s){
        if(i == 'G' || i == 'g') g++;
        else if(i == 'P' || i == 'p') p++;
        else if(i == 'L' || i == 'l') l++;
        else if(i == 'T' || i == 't') t++;
    }
    while(g>0 || p>0 || l>0 || t>0){
        if(g > 0) cout << 'G',g--;
        if(p > 0) cout << 'P',p--;
        if(l > 0) cout << 'L',l--;
        if(t > 0) cout << 'T',t--;
    }
    return 0;
}