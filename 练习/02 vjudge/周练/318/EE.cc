#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool func(int *a,int n,int x,int p){
    int sum = 0,i=0;
    // while(x >= a[i]) sum++,i++,x++;
    for(int i=0;i<n;i++){
        if(x >= a[i]){
            sum ++;
            x++;
        }else return false;
    }

    if(p <= sum) return false;
    

}
int main()
{
    int n,p;cin >> n >> p;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    long long cnt;
    for(int i=1;i<=a[n-1];i++){
        if(func(a,n,i,p)) cnt++;
    }
}