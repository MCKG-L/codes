#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <cstdio>
using namespace std;
int main()
{
    srand(time(nullptr));
    ofstream fout;
    fout.open("a.txt",ios::app);
    cout << "Number    Chinese    Mathematics    English" << endl;
    for(int i=0;i<20;i++){
        // cout << i + 1 << "      ;";
        printf("%2d",i+1);cout << "     ;";
        int k = 3;
        while(k--){
            int x = rand()%100;
            cout << "     ";
            printf("%2d",x);
            cout << "    ";
            if(k) cout << ';';
        }
        cout << endl;
    }
    return 0;
}