/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#include <unordered_map>
using namespace std;
unordered_map<int,string> m_rank{{1,"Ace"},{2,"2"},{3,"3"},{4,"3"},{5,"5"},{6,"6"},{7,"7"},{8,"8"},{9,"9"},{10,"10"},{11,"Jack"},{12,"Queen"},{13,"King"}};
unordered_map<int,string> color{{1,"Clubs"},{2,"Diamonds"},{3,"Hearts"},{0,"Spades"}};
int main()
{
    srand(time(0));
    int k = rand() % 52 + 1;
    cout << k << endl;
    cout << "The card you picked is " << m_rank[int(ceil(k*1.0/4))] << " of " << color[k%4] << endl;
    return 0;
}