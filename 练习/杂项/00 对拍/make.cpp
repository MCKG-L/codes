#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    srand(time(0));
    int n = rand() % 1000 + 2;
    int m = rand() % n + 2;
    cout << n << ' ' << m << endl;
    for(int i=1;i<=n;i++){
        cout << rand() % 1000000 << ' ';
    }
    cout << endl;
    return 0;
}