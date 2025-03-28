#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int s1=1,s2=1;
    for(char i : s) s1 *= (i-'A'+1);
    cin >> s;
    for(char i : s) s2 *= (i-'A'+1);
    if(s1 % 47 == s2 % 47) puts("GO");
    else puts("STAY");
    return 0;
}