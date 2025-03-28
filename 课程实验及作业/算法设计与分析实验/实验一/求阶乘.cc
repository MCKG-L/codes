#include <iostream>
using namespace std;
int f(int x){
    if(x <= 1) return 1;
    return f(x-1) * x;
}
int main()
{
    int x;cin >> x;
    cout << f(x) << endl;
    return 0;
}