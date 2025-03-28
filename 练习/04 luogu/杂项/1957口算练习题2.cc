#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    char mask;
    for(int i=0;i<n;i++){
        char s[10];
        int num1,num2;
//        scanf("%s",s);
		cin >> s;
        if(s[0] == 'a' || s[0] == 'b' || s[0] == 'c'){
            mask = s[0];
            cin >> num1 >> num2;
        }else{
            sscanf(s,"%d",&num1);
            cin >> num2;
        }
        char ss[100];
        memset(ss,0,sizeof(s));//清空
        if(mask == 'a'){
            sprintf(ss,"%d+%d=%d",num1,num2,num1+num2);
        }else if(mask == 'b'){
            sprintf(ss,"%d-%d=%d",num1,num2,num1-num2);
        }else if(mask == 'c'){
            sprintf(ss,"%d*%d=%d",num1,num2,num1*num2);
        }
        cout << ss << '\n' << strlen(ss) << '\n';
    }
    return 0;
}