#include <bits/stdc++.h>
using namespace std;
/*
nth_element函数的作用是将数组中第K小的元素放在第K的位置上（从0开始）
其复杂度为o(n);

*/
int main()
{
    int n,k;;
    cin >> n >> k;
    int a[n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    nth_element(a,a+k,a+n);
    cout << a[k];
    return 0;
}