#include <iostream>
#include <map>
using namespace std;
map<string,string> p;//键->自己 值->祖宗
char c;
string s,l;
string find(string x){//找祖宗 + 路径压缩
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void unite(string a,string b){//认祖宗
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
void func(string s){//如果没出现过，自己就是祖宗
    if(!p.count(s)) p[s] = s;
}
int main()
{
    while(cin >> c){
        if(c == '$') break;
        if(c == '#'){
            cin >> s;func(s);
            l = s;unite(s,p[s]);
        }else if(c == '+'){
            cin >> s;func(s);
            unite(s,l);
        }else if(c == '?'){
            cin >> s;func(s);
            cout << s << ' ' << find(s) << '\n';
        }
        cin.get();//不要也罢，cin过滤空白符
    }
    return 0;
}   