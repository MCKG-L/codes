#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    int mask = 1;
    for(int i=100;i>0&&mask;i--){
        int sum = 0;
        for(int j=1;j<n/21;j++){
            sum = (21*j+7*i)*52;
            if(sum == n){
                cout << i << endl << j;
                mask = 0;
                break;
            }
        }
    }
    return 0;
}