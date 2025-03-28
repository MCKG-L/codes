#include <iostream>
using namespace std;
const int N = 1010;
int a[N];
int pos[N];
int n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    int l = 0,r = n - 1;
    int max_n = n;
    while(l < r){
        if(max_n <= 0) break;
        int pos_max = pos[max_n];
        if(pos_max == l){
            l ++;
            max_n --;
        }else if(pos_max == r){
            r --;
            max_n --;
        }else{
            cout << "YES" << endl;
            // cout << pos_max << "----" << endl;
            // cout << a[pos_max-1] << ' ' << a[pos_max] << ' ' << a[pos_max+1] << endl;
            cout << pos_max << ' ' << pos_max+1 << ' ' << pos_max+2 << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}