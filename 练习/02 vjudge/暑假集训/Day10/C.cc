#include <iostream>
#include <map>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
typedef unsigned long long ULL;
int n,m,P = 131;
string str;
ULL h[N],p[N];
map<ULL,int> mp;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;str = " " + str;
        h[0] = 0;
        // cout << str << endl;
		int k = str.size() - 1;
        for(int i=1;i<=k;i++){
            h[i] = h[i-1]*P+str[i];
        }
        if(!mp.count(h[k])){
            p[0] = 0;
            for(int i=1;i<=k;i++){
                p[i] = p[i-1]*P+str[k-i+1];
            }
            if(!mp.count(p[k])){
                mp[h[k]]++;
            }
        }
    }
    cout << mp.size() << endl;
    return 0;
}