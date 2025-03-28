#include <iostream>
#include <limits.h>
using namespace std;
/*
插入排序

10
7 86 9 4 53 64 12 0 78 5
*/

//函数max(),min(),swap()用头文件 iostream 即可
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void insertSort(int a[],int n){
    if(n == 0 || a == NULL) return;//边界条件
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0 && a[j]>a[j+1];j--){
            swap(a[j],a[j+1]);
        }
        // int j = i;
        // while(j - 1 >= 0 && a[j-1] > a[j]){
        //     swap(a[j-1],a[j]);
        //     j--;
        // }
    }

}
int main()
{
    int n;cin >> n;
    int a[n];
    // int a[] = {7,8,6,5,9,4,1,2,3,7};
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n;i++){
        int min = INT_MAX;//系统最大值，在头文件 limits.h 中
    }

    printArray(a,n);
    insertSort(a,n);
    printArray(a,n);
}