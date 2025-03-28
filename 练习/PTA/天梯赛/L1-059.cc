#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool func(string s){
    int n = s.size()-1;
    if(s[n] == 'g' && s[n-1] == 'n' && s[n-2] == 'o') return true;
    return false;
}
int main()
{
    int n;cin >> n;
    cin.get();
    for(int i=0;i<n;i++){
        string s;
        vector<string> a,b;
        bool m1,m2;
        while(cin >> s){
            if(s.back() == ','){
                a.push_back(s);s.pop_back();m1=func(s);
                break;
            }
            a.push_back(s);
        }
        while(cin >> s){
            if(s.back() == '.'){
                b.push_back(s);s.pop_back();m2=func(s);
                break;
            }
            b.push_back(s);
        }
        if(m1 && m2){
            int l = b.size()-1;
            b[l] = "zhong.",b[l-1] = "ben",b[l-2] = "qiao";
        }
        else{
             cout << "Skipped" << endl;continue;
        }
        // cout << m1 << ' ' << m2 << endl;
        // for(auto i : a){
        //     cout << i << ' ';
        // }
        // for(auto i : b){
        //     cout << i << ' ';
        // }cout << endl;
        for(int i=0;i<a.size();i++){
            cout << a[i] << ' ';
            // if(i != a.size()-1) cout << ' ';
        }
        for(int i=0;i<b.size();i++){
        cout << b[i];
        if(i != b.size()-1) cout << ' ';
        }cout << endl;
    }

}