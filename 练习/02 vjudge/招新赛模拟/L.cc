#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
int pos[N],a[N];
int n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    int l = 1, r = n;
    int max_n = n,min_n = 1;
    while(l < r){
        bool mask1 = false,mask2 = false;
        int pos_min = pos[min_n];
        if(pos_min == l){
            l ++;
            min_n++;
        }else if(pos_min == r){
            r --;
            min_n++;
        }else{
            mask1 = true;
        }
        int pos_max = pos[max_n];
        if(pos_max == l){
            l ++;
            max_n --;
        }else if(pos_max == r){
            r --;
            max_n --;
        }else{
            mask2 = true;
        }
        if(mask1 && mask2){
            cout << l << ' ' << r << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}