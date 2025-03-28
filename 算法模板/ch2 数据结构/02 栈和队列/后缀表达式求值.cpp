#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <sstream>
#include <stack>
using namespace std;
unordered_map<string,int> mp = {{"+",1},{"-",1},{"*",2},{"/",2}};
void solve(){
    string str;
    getline(cin,str);
    stringstream S(str);
    stack<int> nums;
    string s;
    auto cal = [&](string s)->int{
        int x = 0;
        for(auto c : s){
            x = x * 10 + c - '0';
        }
        return x;
    };
    while(S >> s){
        if(mp.count(s)){
            int a = nums.top();nums.pop();
            int b = nums.top();nums.pop();
            int c = 0;
            if(s == "+") c = a + b;
            if(s == "-") c = b - a;
            if(s == "*") c = a * b;
            if(s == "/") c = b / a;
            nums.push(c);
        }else{
            nums.push(cal(s));
        }
    }
    cout << nums.top() << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}