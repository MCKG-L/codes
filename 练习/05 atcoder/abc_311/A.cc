#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;cin >> n;
    set<char> s;
    for(int i=1;i<=n;i++){
        char c;cin >> c;
        if(c == 'A' || c == 'B' || c == 'C') s.insert(c);
        if(s.size() == 3){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}