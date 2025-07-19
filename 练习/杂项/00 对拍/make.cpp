#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using rnd = mt19937_64;
int main()
{
    // std::mt19937_64 rng(time(0));
    // std::uniform_int_distribution<uint64_t> distribution1(10, 100000000);    // 设置范围
    // long long n = distribution1(rng);
    // std::uniform_int_distribution<uint64_t> distribution2(n, 1000000000000000000);
    // long long m = distribution2(rng);
    // cout << n << ' ' << m << endl;
    srand(time(0));
    cout << rand() % 1000 + 10 << ' ' << 1000000000000000000 << endl;
}