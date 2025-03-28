#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> get_divisors(int n){
    vector<int> ans;
    for(int i=1;i<=n/i;i++){
        if(n % i == 0){
            ans.push_back(i);
            if(i != n/i) ans.push_back(n/i);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;cin >> n;
    vector<int> ans = get_divisors(n);
    for(int i : ans){
        cout << i << ' ';
    }
    return 0;
}