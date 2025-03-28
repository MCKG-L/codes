#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int mask[N];
int main()
{
    for(int i=0;i<N;i++)mask[i] = 1;
    int n;cin >> n;
    while(n--){
        double a;
        int t;
        cin >> a >> t;
        for(int i=1;i<=t;i++){
            mask[(int)(i * a)] *= -1;
        }
    }
    for(int i=1;i<N;i++){
        if(mask[i] == -1){
            cout << i;
            break;
        }
    }
    return 0;
}