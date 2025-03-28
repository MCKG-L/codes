#include <iostream>
#include <map>
using namespace std;
map<string,string> p;
string s,l;
void func(string s){
    if(!p.count(s)) p[s] = s;
}
string find(string s){
    if(p[s] != s) p[s] = find(p[s]);
    return p[s];
}
void merge(string s,string l){
    s = find(s),l = find(l);
    if(s != l) p[s] = l;
}
int main()
{
    char op;
    while(cin >> op){
        if(op == '$') break;
        if(op == '#'){
            cin >> l;func(l);
            merge(s,p[s]);
        }else if(op == '+'){
            cin >> s;func(s);
            merge(s,l);
        }else if(op == '?'){
            cin >> s;func(s);
            cout << s << ' ' << find(s) << endl;
        }
    }
    return 0;
}