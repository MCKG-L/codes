#include <iostream>
using namespace std;
int main()
{
    int t;cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        if(a.size() != b.size()){
            cout << -1 << endl;
        }else{
            for(int i=0;i<a.size();i++){
                cout << (a[i]-'0')*(b[i]-'0');
            }
            cout << endl;
        }
    }
    return 0;
}