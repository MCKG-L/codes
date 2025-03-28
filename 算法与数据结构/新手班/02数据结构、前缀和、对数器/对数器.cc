#include <bits/stdc++.h>
using namespace std;
//插入排序
void insertSort(vector<int> &a){
    int n = a.size();
    if(n == 0) return;//边界条件
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0 && a[j]>a[j+1];j--){
            swap(a[j],a[j+1]);
        }
    }

}
//优化的选择排序
void selectSort(vector<int> &a){
    int n = a.size();
    if(n == 0) return;//边界条件
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
vector<int> a;
//产生一个随机长度随机值的数组的函数
void f(int maxlen,int maxvalue){
    int len = rand() % maxlen;
    a.resize(len);
    for(int i=0;i<len;i++){
        a[i] = rand() % maxvalue;
    }
}
bool isSorted(vector<int> a){
    
    int n = a.size();
    if(n < 2) return true;
    int maxn = a[0];
    for(int i=1;i<n;i++){
        if(a[i] < maxn){
            return false;
        }
        maxn = max(maxn,a[i]);
    }
    return true;
}
//对数器
void test(){
    int maxlen = 20;
    int maxvalue = 100;
    int testtimes = 1000000;
   	vector<int> b,temp;
    int mask;
    for(int i=0;i<testtimes;i++){
        f(maxlen,maxvalue);
        b = a;temp = a;
        selectSort(b);
        insertSort(a);
        mask = 0;
        if(!isSorted(a)){
            cout << "插入排序错了" << endl;
            cout << "len: " << temp.size() << endl;
            cout << "排序前: ";
            for(int j=0;j<temp.size();j++){
                cout << temp[j] << " ";
            }
            cout << endl;
            cout << "排序后: ";
            for(int j=0;j<a.size();j++){
                cout << a[j] << " ";
            }
            cout << endl;
            mask = 1;
        }
        if(!isSorted(b)){
            cout << "选择排序错了" << endl;
            cout << "len: " << temp.size() << endl;
            cout << "排序前: ";
            for(int j=0;j<temp.size();j++){
                cout << temp[j] << " ";
            }
            cout << endl;
            cout << "排序后: ";
            for(int j=0;j<b.size();j++){
                cout << b[j] << " ";
            }
            mask = 1;
        }
        if(mask) break;
    }
    if(!mask){
        cout << "你写的插入排序在" << testtimes << "个随机样例中是正确的！" << endl;
        cout << "你写的选择排序在" << testtimes << "个随机样例中是正确的！" << endl;
    }
    
}
int main()
{
    srand((unsigned)time(0));
    test();
//    vector<int> c(3);
//    c[0] = 1;c[1] = 3;c[2] = 1;
//    if(!isSorted(c)){
//        cout << "插入排序错了" << endl;
//    }
    return 0;
}