#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int N = 2e5 + 10;
int a[N],n;
void quick_sort(int l,int r){
    if(l >= r) return;
    int x = a[(l + r) / 2],i = l - 1,j = r + 1;
    while(i < j){
        do i ++;while(a[i] < x);
        do j --;while(a[j] > x);
        if(i < j) swap(a[i],a[j]);
    }
    quick_sort(l,j),quick_sort(j+1,r);
}
int main()
{
    srand(time(NULL));
    // n = rand() % 12 + 1;
    cin >> n;
    // for(int i=0;i<n;i++) a[i] = rand() % 100 + 1;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    quick_sort(0,n-1);
    for(int i=0;i<n;i++)cout << a[i] << ' ';
    cout << endl;
    return 0;
}