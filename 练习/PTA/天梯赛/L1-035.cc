#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    vector<string> p;
    while(cin >> s){
        p.push_back(s);
    }
    int n = p.size() - 1;
    if(n < 2) cout << "Momo... No one is for you ..." << endl;
    else if(n < 14) cout << p[1] << " is the only one for you..." << endl;
    else cout << p[1] << " and " << p[13] << " are inviting you to dinner..." << endl;
    return 0;
}