#include <iostream>
#include <map>
using namespace std;
map<string,int> mp = {{"ACE",1},{"BDF",1},{"CEG",1},{"DFA",1},{"EGB",1},{"FAC",1},{"GBD",1}};

int main()
{
    string s;cin >> s;
    if(mp.count(s)) puts("Yes");
    else puts("No");
    return 0;
}