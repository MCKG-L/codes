#include <iostream>
#include <map>
int f(int n,int a[]){
    int k = 0;
    while(a[k] != n) k++;
    return k;
}
using namespace std;
int main()
{
    string s;cin >> s;
    map<int,int> mp;
    for(auto i : s){
        mp[i-'0']++;
    }
    int a[10],k=0;
    for(auto i=mp.rbegin();i!=mp.rend();i++){
        a[k++] = i->first;
//         a[i->first] = k++;
    }
    int index[11],j=0;
    for(auto i : s){
       index[j++] = f(i-'0',a);
    }
//     for(int i=0;i<11;i++) cout << index[i] << " ";
    cout << "int[] arr = new int[]{";
    for(int i=0;i<k;i++){
        cout << a[i];
        if(i != k-1) cout << ',';
    }cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for(int i=0;i<11;i++){
        cout << index[i];
        if(i != 10) cout << ',';
    }cout << "};";
    return 0;
}