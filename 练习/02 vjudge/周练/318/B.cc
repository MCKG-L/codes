#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<pair<int,int>> p(N);
int main()
{
    int n,x;cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> p[i].first;
        p[i].second = 0;
    }
    p[x].second = 1;
	 
    int cnt = 1;
    int it = p[x].first;
    while(1){
        pair<int,int> s = p[it];
        if(s.second == 0){
            p[it].second = 1;
            cnt++;
            it = s.first;
        }else{
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}