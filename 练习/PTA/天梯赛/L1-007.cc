#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char c;
    c = getchar();
    while(c != '\n'){
        if(c == '-') cout << "fu";
        else if(c == '0') cout << "ling";
        else if(c == '1') cout << "yi";
        else if(c == '2') cout << "er";
        else if(c == '3') cout << "san";
        else if(c == '4') cout << "si";
        else if(c == '5') cout << "wu";
        else if(c == '6') cout << "liu";
        else if(c == '7') cout << "qi";
        else if(c == '8') cout << "ba";
        else if(c == '9') cout << "jiu";
        c = getchar();
        if(c != '\n') cout << " ";
    }
    return 0;
}