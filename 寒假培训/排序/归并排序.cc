#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& a,int low,int mid,int high){
    int *b = new int[high - low + 1];//申请辅助数组
    int i= low,j = mid + 1,k = 0;
    while(i <= mid && j <= high){
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= high) b[k++] = a[j++];
    k = 0;
    for(int i=low;i<=high;i++){
        a[i] = b[k++];
    }
    delete[] b;
}
void merge_sort(vector<int>& a,int low,int high){
    if(low < high){
        int mid = (low + high) >> 1;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}