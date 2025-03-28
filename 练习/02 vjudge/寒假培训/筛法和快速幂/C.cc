#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
int cnt;
bool st[N];
void solve(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            cnt++;
            for(int j=i+i;j<=n;j+=i){
                st[j] = 1;
            }
        }
    }
}
int main()
{
    int N;
    cin >> N;
    solve(N);
    cout << cnt;
}