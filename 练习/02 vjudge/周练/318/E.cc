#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
//暴力超时！！！
bool func(vector<int> &a,int t,int p){
    int sum = 0;
    vector<int> s(a.size());
    iota(s.begin(),s.end(),0);
    do{
    	int x = t;
    	bool mask = 1;
        for(int j=0;j<s.size();j++){
            if(x >= a[s[j]]) x ++;
            else{
            	mask = 0;break;
			}
        }
        if(mask) sum++;
        else continue;
    }while(next_permutation(s.begin(),s.end()));
    if(sum % p != 0) {
        // cout << t << ' ' << sum << "----" << '\n';
        return true;
    }
    return false; 
}
int main()
{
    int n,p;cin >> n >> p;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int cnt = 0;
    for(int i=1;i<=a.back();i++){
        if(func(a,i,p)) ans.push_back(i),cnt++;
    }
    cout << cnt << endl;
    for(int i=0;i<cnt;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}