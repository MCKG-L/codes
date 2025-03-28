#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    int k =0,sum = 0;
    for(int i=a;i<=b;i++){
        printf("%5d",i);
        sum += i;k++;
        if(k % 5 == 0) cout << endl;
    }
    if(k % 5 != 0) cout << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}