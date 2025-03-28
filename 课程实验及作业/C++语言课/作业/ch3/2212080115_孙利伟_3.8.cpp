/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double acount;cin >> acount;
    int Racount = ceil(acount * 100);
    int n_onedollars,n_quarters,n_dimes,n_nickels,n_pennies;
    n_onedollars = Racount / 100;
    Racount %= 100;
    n_quarters = Racount / 25;
    Racount %= 25;
    n_dimes = Racount / 10;
    Racount %= 10;
    n_nickels = Racount / 5;
    Racount %= 5;
    n_pennies = Racount;
    cout << "Your acount " << acount << " consists of " << endl;
    if(n_onedollars == 1) cout << n_onedollars << " dollar" << endl;
    else if(n_onedollars > 1) cout << n_onedollars << " dolors" << endl;
    if(n_quarters == 1) cout << n_quarters << " quarter" << endl;
    else if(n_quarters > 1) cout << n_quarters << " quarters" << endl;
    if(n_dimes == 1) cout << n_dimes << " n_dime" << endl;
    else if(n_dimes > 1) cout << n_dimes << " n_dimes" << endl;
    if(n_nickels == 1) cout << n_nickels << " n_nickel" << endl;
    else if(n_nickels > 1) cout << n_nickels << " n_nickels" << endl;
    if(n_pennies == 1) cout << n_pennies << " n_pennie" << endl;
    else if(n_pennies > 1) cout << n_pennies << " n_pennies" << endl;
    
    return 0;
}