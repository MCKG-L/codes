#include <iostream>
#include <map>
using namespace std;
map<int,int> mp;
/*
map是一种映射 每一个键对应一个值
头文件 map
内部红黑树实现 会按照键的大小自动排序
初始化定义：
map<string,string> mp;
map<string,int> mp;
map<int,node> mp;
特性：map会按照键的顺序从小到大自动排序
*/
//函数方法
int main()
{
    for(int i=0;i<10;i++){
        mp[i*i] = 2 * i;
    }
    /*!!! find() 返回待查找数据（键）的位置，返回一个迭代器；
    如果数据存在返回指向该元素地址的迭代器，否则返回尾迭代器
    相当于指向pair类型的指针，first对应键，second对应值
    */
    auto k = mp.find(3);
    if(k == mp.end()) cout << "NOT FIND" << endl;
    else cout << k->first << " " << k->second << endl;
    cout << "---------------------" << endl;
    /*!!! count() 查找元素是否存在，存在返回1，不存在返回0 */
    if(mp.count(3) == 0) cout << "NO";
    else cout << "YES";
    cout << endl;
    int n = mp.count(3);cout << n << endl;
    // cout << mp.count(3) << endl << mp.count(4) << endl;

    //查找键值是否存在的三种方法
    /*
    1、使用find()函数
    2、使用count()函数
    3、使用[] mp[key] 不存在值为0
    注意：第三种方法，如果不存在相应的key,会自动创建一个相应的键值对，消耗额外的键值对空间
    所以查找元素是否存在时最好用前两种函数方法
    */
    cout << "--------------------" << endl;
    if(mp.count(3)) cout << "YES";else cout << "NO";cout << endl;
    cout << mp.size() << endl;
    if(mp[3]) cout << "YES";else cout << "NO";cout << endl;
    cout << mp.size() << endl;
    mp.erase(3);//删除自动创建的键值对
    //删除操作 erase()函数 有几种重载
    //clear()函数 清空map中的所有元素
    /*
    1、mp.erase(it) it是迭代器 删除迭代器对应的键值对
    2、mp.erase(key) 删除相应的键值对
    3、mp.erase(firsr,last) 删除左闭右开区间迭代器对应的键值对
    */
    cout << "-----------------------" << endl;
    if(mp.count(4)) cout << "YES!";else cout << "NO!";cout << endl;
    cout << mp.size() << endl;
    mp.erase(4);
    if(mp.count(4)) cout << "YES!";else cout << "NO!";cout << endl;
    cout << mp.size() << endl;
    
    /*
    empty()函数 如果为空返回true，否则返回false；
    */

    /*
    size()函数 返回键值对的对数
    */

    /*
    begin()函数 返回指向第一个元素的迭代器
    end()函数 返回指向mp的尾迭代器（指向最后一个元素的下一个地址）
    */

    //插入操作
    /*
    insert()函数 插入时需要构造键值对
    */
    //方式1
    mp.insert(pair<int,int>(3,6));
    //方式2
    mp.insert(make_pair(5,10));
    //方式3
    mp.insert({2,4});
    //方式4
    mp[6] = 12;
    // pair 和 make_pair
    /*
    pair创建时需要写出两个数据的类型 pair<string,int> p;
    make_pair创建时不需要写出数据的类型 make_pair p; make_pair("haha",2);
    make_pair作为函数参数比较方便
    */
    cout << "--------------------" << endl;
    cout << "size: " << mp.size() << endl;
    //map的遍历 使用迭代器进行正反遍历 可以看出map进行了自动的排序（键从小到大）
    //正向遍历 mp.begin() mp.end()
    for(auto i=mp.begin();i!=mp.end();i++){
        cout << i->first << " " << i->second << endl;
    }

    cout << "--------------------" << endl;
    cout << "size: " << mp.size() << endl;
    ///反向遍历 mp.rbegin() mp.rend()
    for(auto i=mp.rbegin();i!=mp.rend();i++){
        cout << i->first << " " << i->second << endl;
    }
    
    //二分查找 lower_bound() upper_bound() 返回迭代器
    // lower_bound() 指向键值大于等于key的第一个元素
    // upper_bound() 指向键值大于key的第一个元素

    //unordered_map 内部用哈希表实现，内部元素杂乱无序
    //map 内部红黑树实现，内部元素按照键的大小自动排序

    //比较 二者函数方法基本一样
    /* map:
    优点：内部红黑树实现，内部元素有序，增删操作时间复杂度为O(logN);
    缺点：占用空间较大
    */
    /* unordered_map 
    优点：内部用哈希表实现 查找速度非常快，适用于大量的查询操作
    缺点：建立哈希表时比较费时间
    */

    //multimap 一个键可以对应多个值
}