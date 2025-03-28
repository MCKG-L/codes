#include <iostream>
#include <vector>
using namespace std;
bool func(string s){
    for(auto i : s){
        if(i < '0' || i > '9'){
            return false;
        }
    }
    if(s == "0") return false;
    if(s.size() == 4) return s <= "1000";
    else if(s.size() > 4) return false;
    return true;
}
int main()
{
    string a,b;
    cin >> a;
    cin.get();
    getline(cin,b);
    bool m = func(a),n = func(b);
    if(!m) a = "?";if(!n) b = "?";
    cout << a << " + " << b << " = ";
    if(m && n){
        vector<int> ans;
        int r = 0;
        for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0;i--,j--){
            if(i >= 0) r += a[i]-'0';
            if(j >= 0) r += b[j]-'0';
            int d = r % 10;
            ans.push_back(d);
            r /= 10;
        }
        if(r != 0) ans.push_back(r);
        for(int i=ans.size()-1;i>=0;i--){
            cout << ans[i];
        }
    }else{
        cout << "?";
    }
    return 0;
}