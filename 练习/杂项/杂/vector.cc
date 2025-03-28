#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a(10);
    for(int i=0;i<10;i++) a[i] = i;
    // vector<int> b(a.begin(),a.begin()+3);
    a.pop_back();
    for(auto i : a) cout << i << ' ';
}