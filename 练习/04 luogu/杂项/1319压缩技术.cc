#include <iostream>
using namespace std;
int main()
{
    int mask = 1;
    int x,n,cnt = 0;
    cin >> n;
    while(cnt < n * n){
        cin >> x;
        for(int i=0;i<x;i++){
            if(cnt % n == 0 && cnt) cout << endl;
            cout << (mask == 1 ? 0 : 1);
            cnt++;
        }
        mask *= -1;
    }
    return 0;
}