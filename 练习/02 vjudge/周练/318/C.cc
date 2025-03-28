#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;cin >> n >> k;
    vector<int> p,s;
    for(int i=0;i<n;i++){
        int x,sum = 0;
        for(int j=0;j<3;j++){
            cin >> x;
            sum += x;
        }
        p.push_back(sum);
        s.push_back(sum);
    }
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++){
        int it = upper_bound(s.begin(),s.end(),p[i]+300) - s.begin();
        int cnt = n - it;
        if(cnt <= k-1) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}