#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> n >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] + n > 'z'){
            s[i] = 'a' + (s[i]+n-'z') - 1;
        }else{
            s[i] += n;
        }

    }
    cout << s;
    return 0;
}