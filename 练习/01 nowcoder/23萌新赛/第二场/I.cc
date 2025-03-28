#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    int t = n,temp = n;
    int cnt = 0;
    while(n){
        cnt ++;
        n -= n & -n;
    }
    int k = 0;
    while(t){
        k ++;
        t /= 2;
    }
    cnt --;
    int sum = (1 << cnt) - 1;
    sum += 1 << (k-1);
    cout << temp - sum << endl;
    return 0;
}