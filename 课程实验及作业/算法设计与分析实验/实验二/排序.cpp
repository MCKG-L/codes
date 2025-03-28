#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int N = 2e5 + 10;
int a[N],b[N],n;
int c[N];
void quick_sort(int l,int r){
    if(l >= r) return;
    int mid = (l + r) / 2;
    int x = a[mid],i = l - 1,j = r + 1;
    while(i < j){
        do i ++;while(a[i] < x);
        do j --;while(a[j] > x);
        if(i < j) swap(a[i],a[j]);
    }
    quick_sort(l,j),quick_sort(j+1,r);
}

void merge_sort(int l,int r){
    if(l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(l,mid),merge_sort(mid+1,r);
    int i = l,j = mid + 1,k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    k = 0;
    for(int i=l;i<=r;i++) a[i] = b[k++];
}
void merge(int a[],int p,int q,int r){
    int x = q - p + 1,y = r - q;
    for(int i=1;i<=x;i++) b[i] = a[p+i-1];
    for(int i=1;i<=y;i++) c[i] = a[q+i];
    int i = 1,j = 1,k = p;
    while(i <= x && j <= y){
        if(b[i] <= c[j]){
            a[k] = b[i];
            i ++;
        }else{
            a[k] = c[j];
            j ++;
        }
        k ++;
    }
    if(i > x){
        while(j <= y) a[k] = c[j],k ++,j ++;
    }else{
        while(i <= x) a[k] = b[i],k ++,i ++;
    }
}
//课本做法
void merge_sort(int a[],int p,int r){
    if(p >= r) return;
    int q = (p + r) / 2;
    merge_sort(a,p,q);
    merge_sort(a,q+1,r);
    merge(a,p,q,r);
}
void insert_sort(){
    for(int i=0;i<n;i++){
        int x = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > x){
            a[j+1] = a[j];
            j --;
        }
        a[j+1] = x;
    }
}
void Bubble_sort(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]) swap(a[j],a[j+1]);
        }
    }
}
int main()
{

    cin >> n;
    // srand(time(NULL));
    // n = rand() % 12 + 1;
    for(int i=0;i<n;i++) cin >> a[i];
    // for(int i=0;i<n;i++) a[i] = rand() % 100;
    // for(int i=0;i<n;i++) cout << a[i] << ' ' ;
    //cout << endl;

    // quick_sort(0,n-1);
    // merge_sort(0,n-1);
    // insert_sort();
    // Bubble_sort();
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}