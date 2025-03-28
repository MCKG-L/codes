#include <iostream>
using namespace std;
int main()
{
    int a[10];
    for(int i=1;i<=8;i++) cin >> a[i];
    bool mask = false;
    for(int i=1;i<=8;i++){
        if(a[i] % 25 != 0){
            cout << "No" << endl;
            mask = 1;
            break;
        }
        if(a[i] < 100 || a[i] > 675){
            cout << "No" << endl;
            mask = 1;
            break;
        }
        if(i < 8 && a[i] > a[i+1]){
            cout << "No" << endl;
            mask = 1;
            break;
        }
    }
    if(!mask) cout << "Yes" << endl;
    return 0;
}