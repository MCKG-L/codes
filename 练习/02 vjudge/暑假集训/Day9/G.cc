#include <iostream>
#include <set>
using namespace std;
/*
最小异或对一定产生自排序后相邻的数对
*/
multiset<int> a,ans;//a存集合中的数，ans，存所有可能为最小值（相邻数）的异或对的值
int main()
{
    int n;cin >> n;
    while(n--){
        int op;cin >> op;
        if(op == 1){
            int x;cin >> x;
            auto it = a.lower_bound(x);
            if(it != a.begin()) ans.insert(x ^ *prev(it));
            if(it != a.end()) ans.insert(x ^ *it);
            if(it != a.begin() && it != a.end()) ans.erase(ans.find(*it ^ *prev(it)));
            a.insert(x);
        }else if(op == 2){
            int x;cin >> x;
            a.erase(a.find(x));
            auto it = a.lower_bound(x);
            if(it != a.end()) ans.erase(ans.find(x ^ *it));
            if(it != a.begin()) ans.erase(ans.find(x ^ *prev(it)));
            if(it != a.begin() && it != a.end()) ans.insert(*it ^ *prev(it));
        }else{
            cout << *ans.begin() << endl;
        }
    }
    return 0;
}