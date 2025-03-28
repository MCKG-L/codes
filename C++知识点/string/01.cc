#include <string>
#include <iostream>
#include <time.h>

using namespace std;
int main()
{
    long long a = 100000000;
    clock_t begin,end;
    begin = clock();
    int t = 1000000;
    string s;
    while(t--)
    s = to_string(a);
    end = clock();
    cout << s << endl;
    cout << "time : " << double(end - begin)/CLOCKS_PER_SEC << "s";
}