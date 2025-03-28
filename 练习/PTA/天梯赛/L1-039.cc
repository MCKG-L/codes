#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
    int N,M;cin >> N;getchar();
    char str[1010];
    cin.getline(str,1010);
    int l = strlen(str);
    if(l % N == 0) M = l / N;
    else M = l / N + 1;
    char a[N][M];
    memset(a,' ',sizeof(a));
    int k = 0;
    for(int i=M-1;i>=0;i--){
        for(int j=0;j<N;j++){
            a[j][i] = str[k++];
            if(k == l) break;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}