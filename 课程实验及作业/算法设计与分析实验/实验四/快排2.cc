#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int N = 2e5 + 10;
int a[N],n;

int Partition(int a[],int p,int r){
    int x = a[p];
    int i = p,j = r + 1;
    while(i < j){
        do j --;while(a[j] > x);
        do i ++;while(a[i] <= x);
        if(i < j) swap(a[i],a[j]);
    }
    return j;
}
void quick_sort(int a[],int p,int r){
    if(p >= r) return;
    int q = Partition(a,p,r);
    swap(a[p],a[q]);
    quick_sort(a,p,q-1);
    quick_sort(a,q+1,r);
}

int main()
{
    srand(time(NULL));
    n = rand() % 12 + 1;
    // cin >> n;
    // for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) a[i] = rand() % 100 + 1;
    for(int i=1;i<=n;i++) cout << a[i] << ' ';
    cout << endl;
    quick_sort(a,1,n);
    for(int i=1;i<=n;i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}