#include <iostream>
using namespace std;
int main()
{
    int k;cin >> k;
    string s;int i = 0;
    while(cin >> s){
        if(s == "End") break;
        if((i - k) % (k + 1) == 0) cout << s << endl;
        else if(s == "ChuiZi") cout << "Bu" << endl;
        else if(s == "JianDao") cout << "ChuiZi" << endl;
        else if(s == "Bu") cout << "JianDao" << endl;
        i++;
    }
    return 0;
}