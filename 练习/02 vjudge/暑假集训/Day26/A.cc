#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;cin >> n;
    set<char> a;
    string s = "Timur";
    for(int i=0;i<s.size();i++) a.insert(s[i]);
    while(n--){
        int k;cin >> k;
        set<char> b;
        for(int i=0;i<k;i++){
            char c;cin >> c;
            b.insert(c);
        }
        if(k != 5 || a != b){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}