#include <iostream>
using namespace std;
const int N = 50;
struct p{
    int id;
    string name;
}a[N];
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].id >> a[i].name;
    }
    for(int i=0;i<n/2;i++){
        int k = a[i].id ? 0 : 1;
        for(int j=n-1;j>=n/2;j--){
            if(a[j].id == k){
                cout << a[i].name << " " << a[j].name << endl;
                a[j].id = -1;
                break;
            }
        }
    }
    return 0;
}