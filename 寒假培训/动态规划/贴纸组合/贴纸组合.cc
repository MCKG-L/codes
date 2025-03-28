#include <bits/stdc++.h>
using namespace std;
/*
    贴纸问题
    给定字符串str，以及一个字符串类型数组arr,目的是用arr中出现的贴纸（可以重复使用），拼出来str，贴纸可以把单个字符剪开使用
    问 最少需要多少张贴纸？
    str = "babac"
    arr = {"ba","c","abcd"};
    ba + ba + c  --> 3
    ba + abcd    --> 2
    答案是2
*/

