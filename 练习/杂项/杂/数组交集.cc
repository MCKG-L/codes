#include <iostream>
using namespace std;
const int N = 105;
int a[N],b[N];
const int M = 1e6;
bool vis[M];
int main()
{
    int n1,n2;
    cin >> n1;
    for(int i=0;i<n1;i++){
        cin >> a[i];
    }
    cin >> n2;
    for(int i=0;i<n2;i++){
        cin >> b[i];
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i] == b[j] && !vis[a[i]]){
                cout << a[i] << "#";
                vis[a[i]] = 1;
            }
        }
    }
    return 0;
}