#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100010;
int n,m,x;
int a[N],b[N];
//双指针算法
int main()
{
    cin >> n >> m >> x;
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    for(int i=0,j=m-1;i<n;i++){
        while(j >= 0 && a[i]+b[j] > x) j--;
        if(a[i] + b[j] == x){
            // cout << i << ' ' << j;
            // break;
            ans.push_back(make_pair(i,j));
        }
    }
    for(auto i : ans){
        cout << i.first << ' ' << i.second << endl;
    }
    
    return 0;
}