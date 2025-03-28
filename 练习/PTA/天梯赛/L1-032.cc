#include <iostream>
using namespace std;
int main()
{
    int n;char c;string s;
    cin >> n >> c;
    cin.get();
    getline(cin,s);
    if(n > s.size()){
        int k = n - s.size();
        for(int i=0;i<k;i++) cout << c;
        cout << s << endl;
    }else{
        for(int i=s.size()-n;i<s.size();i++){
            cout << s[i];
        }
    }
    return 0;
}