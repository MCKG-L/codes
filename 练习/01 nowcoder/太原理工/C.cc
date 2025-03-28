#include <iostream>
#include <set>
using namespace std;
int main()
{
    int k;cin >> k;
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    int ans = 0;
    for(int i=0;i<s1.size();i++){
        set<int> s;
        s.insert(s1[i]-'a');
        s.insert(s2[i]-'a');
        s.insert(s3[i]-'a');
        ans += s.size()-1;
    }
    cout << ans << endl;
    return 0;
}