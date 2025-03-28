#include <iostream>
using namespace std;
//O(logn)
int gcd(int a,int b){
    //a,b不能为0
    // return b ? gcd(b,a%b) : a;
    // if(a == 0 || b == 0) return 0;
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
    return 0;
}