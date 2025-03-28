#include <iostream>
using namespace std;
int main()
{
    string s,p;
    cin >> s >> p;
    int n = s.size();
    if(n == p.size()){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] != p[i]) cnt++;
        }
        if(cnt == 1){
            cout << "YES" << endl;
            return 0;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }else if(n == p.size()+1){
        p += '1';
        int k = 0,cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] != p[i-k]){
                cnt ++;k = 1;
            }
            if(cnt >= 2){
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
        return 0;
    }else if(n == p.size()-1){
        s += '1';
        int k = 0,cnt = 0;
        n = p.size();
        for(int i=0;i<n;i++){
            if(s[i-k] != p[i]){
                cnt ++;k = 1;
            }
            if(cnt >= 2){
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
        return 0;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}