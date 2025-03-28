#include <iostream>
#include <map>
using namespace std;
map<int,int> ans;
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(!ans.count(x+9) && !ans.count(x-9)){
            ans.insert({x,1});
        }
    }
    cout << ans.size() << endl;
    return 0;
}