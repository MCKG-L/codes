#include <bits/stdc++.h>
using namespace std;
const int N = 16005;
int cnt[N];
int main()
{
    int s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    int a[s1+1],b[s2+1],c[s3+1];
    for(int i=1;i<=s1;i++) a[i] = i;
    for(int i=1;i<=s2;i++) b[i] = i;
    for(int i=1;i<=s3;i++) c[i] = i;
    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            for(int k=1;k<=s3;k++){
                int sum = i + j + k;
                cnt[sum]++;
            }
        }
    }
    int ans = 0,s = 0;
    for(int i=1;i<=N;i++){
        if(cnt[i] > s){
            s = cnt[i];
            ans = i;
        }
    }
    cout << ans;
    return 0;
}