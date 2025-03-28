#include <iostream>
#include <set>
#include <algorithm>
#define endl '\n'
using namespace std;
/*
使用对顶堆的思想，使用set实现（修改比较方便），维护其中一个set的大小始终为n/2+1
则它的最后一个元素始终为中位数
*/
const int N = 1e6 + 10;
int a[N],b[N];
int n,m;
int M;//s1的大小
multiset<int> s1,s2;
void modify(){
    //维护保证s1的数目为M,其最后一个元素即为中位数
    while(s1.size() < M){
        auto it = s2.begin();
        int t = *it;
        s1.insert(t);
        s2.erase(it);
    }
    while(s1.size() > M){
        // auto it = s1.rbegin();
        auto it = prev(s1.end());
        int t = *it;
        s1.erase(it);//erase只能用正向迭代器
        s2.insert(t);
    }
}
void solve(){
    cin >> n >> m;//n为奇数
    M = n / 2 + 1;
    for(int i=1;i<=n;i++) cin >> a[i],b[i] = a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=M;i++) s1.insert(a[i]);
    for(int i=M+1;i<=n;i++) s2.insert(a[i]);

    while(m--){
        int p,x;
        cin >> p >> x;
        int k = b[p];
        b[p] = x;
        //删除
        if(k <= *s1.rbegin()) s1.erase(s1.find(k));
        else s2.erase(s2.find(k));
        //插入
        if(x < *s2.begin()) s1.insert(x);
        else s2.insert(x);
        modify();
        cout << (*s1.rbegin()) << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}