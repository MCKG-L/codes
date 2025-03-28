#include <iostream>
#include <map>
using namespace std;
map<string,string> mp;
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string a,b;
        cin >> a >> b;
        mp[a] = b;
    }
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        cout << mp[s];
        if(i != m-1) cout << ' ';
    }
    // cout << endl;
    return 0;
}