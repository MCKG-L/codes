#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>::iterator m_unique(vector<int> &a){
    //双指针算法
    int j = 0;
    for(int i=0;i<a.size();i++){
        if(!i || a[i] != a[i-1]){
            a[j++] = a[i];
        }
    }
    return a.begin() + j;
}
int main()
{
    vector<int> a;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a.push_back(x);
    }
    // auto x = unique(a.begin(),a.end());
    auto x = m_unique(a);
    for(auto i : a){
        cout << i << " ";
    }

}