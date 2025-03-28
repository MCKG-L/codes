#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <ctype.h>
using namespace std;
const int N = 1e4+5;
char a[N],b[N];
map<char,int> mp;
int main()
{
    fgets(a,N,stdin);
    fgets(b,N,stdin);
    for(int i=0;i<strlen(b);i++){
    	// if(isalpha(b[i]))
        mp[b[i]]++;
    }
    int n = strlen(a);
    for(int i=0;i<n;i++){
        if(mp.count(a[i])){
            a[i] = '\0';
        }
    }
    for(int i=0;i<n;i++){
    	if(a[i] != '\0')
        printf("%c",a[i]);
    }
    return 0;
}