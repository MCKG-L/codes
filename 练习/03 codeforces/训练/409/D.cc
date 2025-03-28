#include <iostream>
#include <unordered_map>
#include <cstring>
#define endl '\n'
using namespace std;
unordered_map<int,int> mp = {{1,1},{2,4},{3,7},{4,2},{5,5},{6,8},{7,3},{8,6},{9,9}};
int a[10][10];
void solve(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            char c;
            cin.get(c);
            if(c == '\n'){j--;continue;}
            a[i][j] = c - '0';
        }
    }
    for(int col=1;col<=9;col++){
        int i = col,j = mp[i];
        int aa = (col == 1 || col == 4 || col == 7) ? col : col-1;
        int bb = (i == 1 || i == 4)? j + 1 : j;
        if(i == 7) bb = j - 1;
        a[i][j] = a[aa][bb];
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout << a[i][j];
        }
        // if(i != 9) cout << endl;
        cout << endl;
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}