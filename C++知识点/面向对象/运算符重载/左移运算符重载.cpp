#include <iostream>
using namespace std;
class Person{
friend ostream& operator<< (ostream &cout,Person &p);
public:
    Person(int a,int b){
        m_a = a;
        m_b = b;
    }

    // 1、成员函数重载左移运算符 不使用 无法实现效果
    // void operator<< (Person &p){
    // }
private:
    int m_a;
    int m_b;
};
// 2、利用全局函数重载左移运算符
ostream& operator<< (ostream &cout,Person &p){
    cout << "m_a = " << p.m_a << ' ' << "m_b = " << p.m_b;
    //换行问题 链式编程 返回值不是void，应该返回cout
    return cout;
}
void test(){
    Person p(10,10);
    cout << p << endl;
}
int main()
{
    test();
    return 0;
}