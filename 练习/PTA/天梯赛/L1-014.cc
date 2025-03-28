#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    int l = n + 1 >> 1;
    char c;cin >> c;
    for(int i=0;i<l;i++){
        for(int j=0;j<n;j++){
            cout << c;
        }
        cout << endl;
    }
    return 0;
}