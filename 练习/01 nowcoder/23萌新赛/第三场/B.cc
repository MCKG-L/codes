#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int> a;
int n,k;
int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    n = a.size();
    for(int i=0;i<k && i<n;i++){
        if(a[i] != i){
            cout << i << endl;
            return 0;
        }
    }
    if(n >= k){
        cout << k << endl;
    }else{
        cout << a.back() + 1 << endl;
    }
    return 0;
}