#include <bits/stdc++.h>
using namespace std;
const int N = 110;
string a[N];
int n;
int main()
{
    cin >> n;
    int pos = 0,mn = 1e9 + 10;;
    for(int i=0;i<n;i++){
        int x;
        cin >> a[i] >> x;
        if(x < mn){
            mn = x;
            pos = i;
        }
    }
    for(int i=pos;i<n;i++){
        cout << a[i] << endl;
    }
    for(int i=0;i<pos;i++){
        cout << a[i] << endl;
    }
    return 0;
}