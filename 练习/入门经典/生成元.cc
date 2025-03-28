#include <iostream>
#include <string.h>
using namespace std;
/*
若x+x的各个数字之和等于y，则成x为y的生成元
给出n，求n的最小生成元
*/
const int N = 100100;
int ans[N];
int main()
{
    int t,n;
    memset(ans,0,sizeof(ans));
    for(int m=1;m<N;m++){
        int x = m,y = m;
        while(x)y += x%10,x/=10;
        if(!ans[y] || ans[y]>m) ans[y] = m;
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
