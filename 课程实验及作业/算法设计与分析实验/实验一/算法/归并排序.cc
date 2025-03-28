#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int N = 10010;
int a[N],b[N];
void merge_sort(int l,int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l,mid);
    merge_sort(mid + 1,r);

    //合并
    int i = l,j = mid + 1,k = 0;
    while(i <= mid && j <= r){
        if(a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    k = 0;
    for(int i=l;i<=r;i++){
        a[i] = b[k++];
    }

}
int main()
{
    // cout << "请输入数据" << endl;
    srand(time(NULL));
    int n;n = rand() % 12 + 1;
    for(int i=0;i<n;i++) a[i] = rand() % 100 + 1;
    for(int i=0;i<n;i++) cout << a[i] << ' ';
    cout << endl;
    merge_sort(0,n-1);

    for(int i=0;i<n;i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}
