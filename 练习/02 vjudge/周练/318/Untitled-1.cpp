#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int N;cin >> N;getchar();
    char s[1010];
    cin.getline(s,1010);
    // cout << strlen(s);
    int n = strlen(s);
    // int l = n / N ? n / N + 1 : n / N;
    int l;
    if(n % N == 0) l = n / N;
    else l = n / N + 1;
    char ans[N][l];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<l;j++){
    //         ans[i][j] = ' ';
    //     }
    // }
    memset(ans,' ',sizeof(ans));
    int k = 0;
    for(int i=l-1;i>=0;i--){
        // if(k == n) break;
        for(int j=0;j<N;j++){
            ans[j][i] = s[k++];
            if(k == n) break;
        }
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<l;j++){
    //         printf("%c",ans[i][j]);
    //     }
    //     putchar('\n');
    // }
    for(int i=0;i<N;i++){
        for(int j=0;j<l;j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}