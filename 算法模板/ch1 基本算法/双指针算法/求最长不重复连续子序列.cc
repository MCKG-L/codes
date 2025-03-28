#include <iostream>
#include <map>
using namespace std; 
//双指针算法可以降低时间复杂度
// 1 2 3 3 4 5 6 7 8 8 9 0 0
const int N = 100010;
int a[N],s[N];
map<int,int> mp;
int n;
int main()
{
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0,j=0;i<n;i++){
        // s[a[i]]++;
        // while(s[a[i]] > 1){
        //     s[a[j]]--;
        //     j++;
        // }
        mp[a[i]]++;
        while(mp[a[i]]>1){
            mp[a[j]]--;
            j++;
        }
        ans = max(ans,i-j+1);
    }
    int ans2 = 0;
    // for(int i=1,j=0;i<n;i++){
    //     while(i < n &&  a[i] != a[i-1]) i ++;
    //     ans2 = max(ans2,i-j);
    //     while(i < n && a[i] == a[i-1]) i ++;
    //     i --;
    //     j = i;
    // }
    cout << ans << endl;
    cout << ans2 << endl;
    return 0;
}