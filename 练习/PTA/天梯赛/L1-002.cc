#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    char ch;cin >> ch;
    n--;
    int i = 1;
    while(n > 4 * i + 2){
        n-=4*i+2;
        i++;
    }
    for(int k=0;k<i;k++){
        for(int j=0;j<k;j++) cout << ' ';
        for(int j=0;j<2*(i-k-1)+1;j++) cout << ch;
        cout << endl;
    }
    for(int k=1;k<i;k++){
        for(int j=0;j<i-k-1;j++) cout << ' ';
        for(int j=0;j<2*k+1;j++) cout << ch;
        cout << endl;
    }
    cout << n << endl;
    return 0;
}