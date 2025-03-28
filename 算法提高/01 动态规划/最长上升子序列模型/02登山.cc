#include <iostream>
using namespace std;
const int N = 1010;
int n;
int a[N];
int dp_l[N],dp_r[N];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    //求从左到右以每个点结尾的最大上升子序列长度
    for(int i=1;i<=n;i++){
        dp_l[i] = 1;
        for(int j=1;j<i;j++){
            if(a[j] < a[i]){
                dp_l[i] = max(dp_l[i],dp_l[j]+1);
            }
        }
    }
    //从右到左求以每个点结尾的最大上升子序列长度
    for(int i=n;i>=1;i--){
        dp_r[i] = 1;
        for(int j=n;j>i;j--){
            if(a[j] < a[i]){
                dp_r[i] = max(dp_r[i],dp_r[j]+1);
            }
        }
    }
    int ans = 0;
    // for(int i=1;i<=n;i++){
    //     ans = max(ans,dp_l[i]);
    //     for(int j=i+1;j<=n;j++){
    //         if(a[j] < a[i]) ans = max(ans,dp_l[i]+dp_r[j]);
    //     }
    // }
    for(int i=1;i<=n;i++){
        ans = max(ans,dp_l[i]+dp_r[i]-1);
    }
    cout << ans << endl;
    return 0;
}