#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    int p = s1.find(s2);
    while(p != -1){
        s1.erase(p,s2.size());
        //s1.erase(s1.begin()+p,s1.begin()+p+s2.size());
        p = s1.find(s2);
    }
    cout << s1;
}