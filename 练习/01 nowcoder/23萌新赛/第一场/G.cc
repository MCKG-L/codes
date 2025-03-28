#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin >> n;
    string s;cin >> s;
    int s1 = 0;
    for(int i=0;i<n;i++){
        while(s[i] == '1') i++,s1++;
        if(s1){
            ans.push_back(s1);
            s1 = 0;
        }
    }
    int res = 0;
    sort(ans.begin(),ans.end());
    if(ans.size() == 0) res = 0;
    else if(ans.size() == 1) res = ans[0];
    else res = ans.back() + ans[ans.size()-2];
    cout << res << endl;
    return 0;
}