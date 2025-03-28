#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
这样写速度更慢，标准写法见快速排序2
*/
int part(vector<int>&a,int first,int last){
    int i = first,j = last,mask = a[first];//基准元素
    while(i < j){
        while(i < j and a[j] > mask) j--;//从右边找到第一个小于等于基准元素的位置
        if(i < j) swap(a[i++],a[j]);//交换元素
        while(i < j and a[i] <= mask) i++;//从左边找到第一个大于基准元素的位置
        if(i < j) swap(a[i],a[j--]);//交换元素
    }
    return i;//返回一次划分后基准元素位置
}
void quick_sort(vector<int>& a,int first,int last){
    if(first < last){
        int mid = part(a,first,last);
        quick_sort(a,first,mid-1);//左区间递归快排
        quick_sort(a,mid+1,last);//右区间递归快排
    }
}

int main()
{
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    //在使用快速排序之前打乱数组元素，防止出现已经基本排好序的情况（此时sort的时间复杂度约为O(n^2) ）;
    random_shuffle(a.begin(),a.end());
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}