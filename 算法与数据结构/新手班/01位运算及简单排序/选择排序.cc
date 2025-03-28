#include <iostream>
#include <limits.h>
using namespace std;
/*
选择排序

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
void selectSort(int a[],int n){
    if(n == 0 || a == NULL) return;//边界条件
    for(int i=0;i<n;i++){
        int Minindex = i;
        for(int j=i+1;j<n;j++){
            //找到范围内最小值的位置
            Minindex = a[j] <  a[Minindex] ? j : Minindex;
        }
        swap(a[i],a[Minindex]);
    }
}
//优化的选择排序
void selectSort(int a[],int n){
    if(n == 0 || a == NULL) return;//边界条件
    for(int i=0;i<(n+1)/2;i++){
        int Minindex = i;
        int Maxindex = i;
        for(int j=i+1;j<n-i;j++){
            //找到范围内最小值的位置
            Minindex = a[j] < a[Minindex] ? j : Minindex;
            Maxindex = a[j] > a[Maxindex] ? j : Maxindex;
        }
        swap(a[i],a[Minindex]);
        if(Maxindex == i){//如果最大值位置在i处，更新最大值位置
            Maxindex = Minindex;
        }
        swap(a[n-1-i],a[Maxindex]);
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
    selectSort(a,n);
    printArray(a,n);
}