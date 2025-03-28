#include <iostream>
#include <limits.h>
using namespace std;
/*
冒泡排序
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
void bubbleSort(int a[],int n){
    if(n == 0 || a == NULL) return;//边界条件
    for(int i=0;i<n-1;i++){
        int mask = 1;
        for(int j=0;j<n-1-i;j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                mask = 0;
            }
        }
        if(mask) break;
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
    bubbleSort(a,n);
    printArray(a,n);
}