#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<char,double> mp;
    mp['C']=12.01,mp['H']=1.008;
    mp['O']=16.00,mp['N']=14.01;
    string s;cin >> s;
    double sum = 0,t;
    for(int i=0;i<s.size();){
    	double ss = 0;
        if(s[i]=='C'||s[i]=='H'||s[i]=='O'||s[i]=='N')t = mp[s[i]],i++;
        while(s[i]>='0'&&s[i]<='9') ss = ss*10+(s[i]-'0'),i++;
        if(ss == 0) ss = 1;sum += t * ss;
    }
    cout << sum << endl;
    return 0;
}