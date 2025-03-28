#include <iostream>
#include <vector>
using namespace std;
int cnt[26];
const int N = 1e5 +10;
char s[N],str[N];
int main()
{
    int n;cin >> n;
    cin >> s >> str;
    vector<pair<int,char>> p;
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
        if(s[i] != str[i]){
            p.push_back({make_pair(i,s[i])});
        }
        if(p.size() > 2) break;
    }
    // cout << p.size() << endl;
    // cout << p[0].first << ' ' << p[0].second << endl;
    if(p.size() == 2){
        if(str[p[0].first] == p[1].second && str[p[1].first] == p[0].second){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else if(p.size() == 0){
        bool mask = false;
        for(int i=0;i<26;i++){
            if(cnt[i] >= 2){
                mask = true;
                break;
            }
        }
        if(mask) cout << "YES" << endl;
        else cout << "NO" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}