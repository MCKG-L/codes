#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 10010;
int a[5];
int cnt[6];
unordered_map<char,int> c{{'W',0},{'U',1},{'B',2},{'G',3},{'R',4},{'O',5}};
int main()
{
    int t;cin >> t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        int n;cin >> n;
        for(int i=0;i<n;i++){
            char op;cin >> op;
            a[c[op]]++;
        }
        int m;cin >> m;
        while(m--){
            string s;cin >> s;
            for(auto i : s) cnt[c[i]]++;
        }
        int res = 0;bool mask = 1;
        for(int i=0;i<5;i++){
            if(a[i] < cnt[i]){
                mask = 0;break;
            }
            res += a[i] - cnt[i];
        }
        if(res < cnt[5]) mask = 0;
        if(mask) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}