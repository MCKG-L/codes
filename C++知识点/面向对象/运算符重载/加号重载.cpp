#include <iostream>
using namespace std;
// 加号运算符重载
// 1、成员函数重载加号
class Person{
    public:
    Person operator+ (Person &p){
        Person p2;
        p2.m_a = this->m_a + p.m_a;
        p2.m_b = this->m_b + p.m_b;
        return p2;
    }
    int m_a;
    int m_b;
};
// 2、全局函数重载加号
// Person operator+ (Person p1,Person p2){
//     Person p3;
//     p3.m_a = p1.m_a + p2.m_a;
//     p3.m_b = p1.m_b + p3.m_b;
//     return p3;
// }
void test(){
    Person p1;
    p1.m_a = 10;
    p1.m_b = 20;
    Person p2;
    p2.m_a = 20;
    p2.m_b = 10;
    Person p3 = p1 + p2;
    cout << p3.m_a << ' ' << p3.m_b << endl;
}
int main()
{
    test();
    return 0;
}