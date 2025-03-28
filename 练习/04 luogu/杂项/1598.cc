#include <iostream>
using namespace std;
int cnt[26];
int main()
{
    string s;
    for(int i=0;i<4;i++){
        getline(cin,s);
        for(char j : s){
            if(j >= 'A' && j <= 'Z') cnt[j-'A']++;
        }
    }
    // for(int i=0;i<26;i++) cout << cnt[i] << ' ';
    int k = 0;
    for(int i=0;i<26;i++) k = max(k,cnt[i]);
    for(int i=k;i>0;i--){
        for(int j=0;j<26;j++){
            if(cnt[j] >= i) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
    for(int i=0;i<26;i++){
        cout << (char)('A' + i) << ' ';
    }
    return 0;
}