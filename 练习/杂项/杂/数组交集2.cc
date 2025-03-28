#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
/*
9
2 5 10 17 10 8 5 10 12
6
12 8 10 17 5 2
*/
using namespace std;
using PII = pair<int,int>;
const int N = 105;
vector<PII> a;
map<int,int> mp;
bool cmp1(PII a,PII b){
    return a.second < b.second;
}
bool cmp2(PII a,PII b){
    return a.first < b.first;
}
bool Myfunc(PII a,PII b){
    return a.second == b.second;
}
int main()
{
    int n1,n2;
    cin >> n1;
    for(int i=0;i<n1;i++){
        int x;cin >> x;
        a.push_back((PII){i,x});
        // a[i].first = i;
        // a[i].second = x;
    }
    //     for(int i=0;i<n1;i++){
    //     // if(mp.count(a[i].second)){
    //     //     cout << a[i].second << "#";
    //     // }
    //     cout << a[i].first << " " << a[i].second << "  ";
    // }
    sort(a.begin(),a.end(),cmp1);
    int n = unique(a.begin(),a.end(),Myfunc) - a.begin();
    a.erase(a.begin(),a.end());
    sort(a.begin(),a.end(),cmp2);
    cin >> n2;
    for(int i=0;i<n2;i++){
        int x;cin >> x;
        mp[x]++;
    }
    for(int i=0;i<n-1;i++){
        // if(mp.count(a[i].second)){
        //     cout << a[i].second << "#";
        // }
        cout << a[i].first << " " << a[i].second << "  ";
    }
    return 0;
}