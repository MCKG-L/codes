#include <iostream>
using namespace std;
int main()
{
    int sa=0,sb=0,a,b;
    cin >> a >> b;
    for(int i=0;i<3;i++){
        int x;cin >> x;
        if(x == 0) sa++;
        else sb ++;
    }
    if(a > b && sa != 0 && sb != 3){
        
        cout << "The winner is a: " << a << " + "  << sa << endl;
    }else{
        cout << "The winner is b: " << b << " + " << sb << endl; 
    }
    return 0;
}