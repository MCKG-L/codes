#include <iostream>
#include <map>
using namespace std;
int main()
{
  int t = 0;cin >> t;
  while(t--){
    map<char,int> mp;
    string s;cin >> s;
    for(auto i : s) mp[i] ++;
    if(mp.size() != 2) cout << "No" << endl;
    else{
      bool f = 1;
      for(auto i : mp){
        if(i.second == 2){
          f = 0;
        }
      }
      if(f) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}