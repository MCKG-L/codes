#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
/*
问题描述：假设有一个无限长的数轴，数轴上的所有点对应的数都是0

首先进行n次操作，每次将x位置上的数加上c

然后进行m次询问，每次询问包含两个整数l和r，求出区间[l,r]之间上所有数的和
*/
const int N = 3e5 + 10;
int n,m;
int a[N],s[N];//离散化后的数据数组和前缀和数组
vector<int> alls;//需要离散化的值 
vector<PII> adds,query;
//二分查找 相当于lower_bound()
//映射函数 1 ~ n
int find(int x){
    int l = 0,r = alls.size()-1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}
int main()
{   

    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x,c;
        cin >> x >> c;
        adds.push_back({x,c});
        alls.push_back(x);
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    //去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    for(auto it = adds.begin();it!=adds.end();it++){
        int x = find(it->first);
        a[x] += it->second;
    }

    //求前缀和
    for(int i=1;i<=alls.size();i++){
        s[i] = s[i-1] + a[i];
    }

    //处理询问
    for(auto item : query){
        int l = find(item.first),r = find(item.second);
        cout << s[r]-s[l-1] << endl;
    }
    return 0;
}
