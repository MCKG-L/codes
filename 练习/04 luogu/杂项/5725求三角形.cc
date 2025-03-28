#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    int mask = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mask < 10){
                cout << 0 << mask++;
            }else{
                cout << mask++;
            }
        }
        cout << endl;
    }
    cout << endl;
    mask = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j < (n - i - 1)){
                cout << "  ";
            }else if(mask < 10){
                cout << 0 << mask++;
            }else{
                cout << mask++;
            }
        }
        cout << endl;
    }
    return 0;
}