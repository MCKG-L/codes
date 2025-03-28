#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    cin.ignore();
    while(n--)
    {
        string s;
        getline(cin,s);
        cout<<s<<endl<<"AI: ";
        while(s[0]==' ') s.erase(s.begin());
        while(s[s.length()-1]==' ') s.erase(s.end()-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                while(s[i+1]==' ') s.erase(s.begin()+i+1);
                if(s[i+1]<'0' || s[i+1]>'9' && s[i+1]<'A' || s[i+1]>'Z' && s[i+1]<'a' || s[i+1]>'z')
                    s.erase(s.begin()+i);  
            }
        }
        for(int i=0;i<s.length();i++)
            if(s[i]>='A' && s[i]<='Z' && s[i]!='I')
                s[i]-='A'-'a';
        
        for(int i=0;;i++)
        {
            i=s.find("can you",i);
            if(i==-1) break;
			if ((i == 0 || s[i - 1]<'0' || s[i - 1]>'9'&&s[i - 1]<'A' || s[i - 1]>'Z'&&s[i - 1]<'a' || s[i - 1]>'z') && (i + 7 == s.length() || s[i + 7]<'0' || s[i + 7]>'9'&&s[i + 7]<'A' || s[i + 7]>'Z'&&s[i + 7]<'a' || s[i + 7]>'z'))
                s.replace(i,7,"A can");
        }
        for(int i=0;;i++)
        {
            i=s.find("could you",i);
            if(i==-1) break;
			if ((i == 0 || s[i - 1]<'0' || s[i - 1]>'9'&&s[i - 1]<'A' || s[i - 1]>'Z'&&s[i - 1]<'a' || s[i - 1]>'z') && (i + 9 == s.length() || s[i + 9]<'0' || s[i + 9]>'9'&&s[i + 9]<'A' || s[i + 9]>'Z'&&s[i + 9]<'a' || s[i + 9]>'z'))
                s.replace(i,9,"A could");
        }
        for(int i=0;;i++)
        {
            i=s.find("I",i);
            if(i==-1) break;
			if ((i == 0 || s[i - 1]<'0' || s[i - 1]>'9'&&s[i - 1]<'A' || s[i - 1]>'Z'&&s[i - 1]<'a' || s[i - 1]>'z') && (i + 1 == s.length() || s[i +1]<'0' || s[i + 1]>'9'&&s[i + 1]<'A' || s[i + 1]>'Z'&&s[i + 1]<'a' || s[i + 1]>'z'))
                s.replace(i,1,"you");
        }
        for(int i=0;;i++)
        {
            i=s.find("me",i);
            if(i==-1) break;
			if ((i == 0 || s[i - 1]<'0' || s[i - 1]>'9'&&s[i - 1]<'A' || s[i - 1]>'Z'&&s[i - 1]<'a' || s[i - 1]>'z') && (i + 2 == s.length() || s[i + 2]<'0' || s[i +2]>'9'&&s[i + 2]<'A' || s[i +2]>'Z'&&s[i + 2]<'a' || s[i + 2]>'z'))
                s.replace(i,2,"you");
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?') s[i]='!';
            if(s[i]=='A') s[i]='I';
        }
        cout<<s<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}