#include <iostream>
#include <functional>
using namespace std;
void move(int n,char a,char b,char c){
    if(n > 1){
        move(n-1,a,c,b);
        cout << n << ' ' << a << ' ' << b << endl;
        move(n-1,c,b,a);
    }
    else{
        cout << n << ' ' << a << ' ' << b << endl;
    }
}
int main()
{
    int n;cin >> n;
    // function<void(int,char,char,char)> dfs = [&](int n,char a,char b,char c) -> void{
    //     if(n > 1){
    //         dfs(n-1,a,c,b);
    //         cout << n << ' ' << a << ' ' << b << endl;
    //         dfs(n-1,c,b,a);
    //     }else{
    //         cout << n << ' ' << a << ' ' << b << endl;
    //     }
    // };
    // dfs(n,'A','B','C');
    move(n,'A','B','C');
    return 0;
}