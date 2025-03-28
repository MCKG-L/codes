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
    cout << "Your acount " << acount << " consists of " << endl << 
    "  " << n_onedollars << " dollars" << endl << 
    "  " << n_quarters << " quarters" << endl << 
    "  " << n_dimes << " dimes" << endl << 
    "  " << n_nickels << " nickels" << endl <<
    "  " << n_pennies << " pennies" << endl;
    return 0;
}