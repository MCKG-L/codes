#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    //初始化
    vector<int> a;
    vector<int> b(10);
    vector<int> c(10,1);//长度为10，每个数都为1
    vector<int> d[10];//vector数组
    //操作
    // a.empty();//返回是否为空
    // a.size();//返回大小
    // a.clear();//清空
    // a.front();
    // a.back();
    // a.pop_back();

    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    //遍历
    for(int i=0;i<a.size();i++) cout << a[i] << ' ';
    cout << endl;
    for(vector<int>::iterator i=a.begin();i!=a.end();i++){
        cout << *i << ' ';
    }
    cout << endl;
    for(int i : a) cout << i << ' ';
    cout << endl;
    //支持比较运算 按照字典序
    for(int i=0;i<10;i++) b[i] = i;
    for(int i=0;i<a.size();i++) cout << a[i] << ' ';
    cout << endl;
    if(a == b) cout << "Yes";
    else cout << "No";
    cout << endl;

    //pair
    pair<int,string> p;
    p = make_pair(1,"abc");
    //支持比较运算 按照字典序
    //存储三元组
    pair<int,pair<int,string>> pp;
}