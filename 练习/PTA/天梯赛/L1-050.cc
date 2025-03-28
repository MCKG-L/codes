#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,a;
    cin >> n >> a;
    char ans[n];
    int x = pow(26,n);
    a = x - a;//转化为正序
    for(int i=0;i<n;i++){
        ans[i] = 'a' + a%26;
        a /= 26;
    }
    for(int i=n-1;i>=0;i--){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}