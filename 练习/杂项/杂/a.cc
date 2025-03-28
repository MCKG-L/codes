#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int,int> mp;
    mp.insert({1,2});
    mp.insert({2,3});
    mp.insert({1,5});
    for(auto i : mp){
        cout << i.first << " " << i.second << endl;
    }
}