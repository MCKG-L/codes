#include <bits/stdc++.h>
using namespace std;
int m_binary_search(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(a[mid] == x) return mid;
        else if(a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
	return -1;
}
int main()
{
    int n;cin >> n;
    int a[n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int m,x;
    cin >> m;
    while(m--){
        cin >> x;
        cout << m_binary_search(a,n,x) << endl;
    }
    return 0;
}