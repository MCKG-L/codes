#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<string,string> mp = {{"one","01"},{"two","04"},{"three","09"},{"four","16"},{"five","25"},{"six","36"},{"seven","49"},
{"eight","64"},{"nine","81"},{"ten","00"},{"eleven","21"},{"twelve","44"},{"thirteen","69"},{"fourteen","96"},{"fifteen","25"},{"sixteen","56"},
{"seventeen","89"},{"eighteen","24"},{"nineteen","61"},{"twenty","00"},{"a","01"},{"both","04"},{"another","01"},{"first","01"},{"second","04"},
{"third","09"}};
vector<string> ans(10);
bool cmp(string a,string b){
    return a+b < b+a;
}
int main()
{
    string s;
    int n = 0;
    while(cin >> s){
        if(s == ".")break;
        if(mp.count(s)){
            ans[n++] = mp[s];
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    string res = "0";
    for(int i=0;i<n;i++){
        res += ans[i];
    }
    reverse(res.begin(),res.end());
    while(res.back()=='0' && res.size() > 1) res.pop_back();
    reverse(res.begin(),res.end());
    cout << res << endl;
    return 0;
}