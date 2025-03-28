#include <bits/stdc++.h>
using namespace std;
/*
判断化学方程式是否配平
11
H2+O2=H2O
2H2+O2=2H2O
H2+Cl2=2NaCl
H2+Cl2=2HCl
CH4+2O2=CO2+2H2O
CaCl2+2AgNO3=Ca(NO3)2+2AgCl
3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2
3Ba(OH)2+2H3PO4=Ba3(PO4)2+6H2O
4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH
Cu+As=Cs+Au
*/
unordered_map<string, int> mp;//  全局图
int computenum(const string& s,int& start){  // start是数字的开头 显然 计算过后的start 指向的不再是数字
    int res = 0;   //  初值为0
    while(start<s.size() and isdigit(s[start])){
        res = res * 10 + (s[start] - '0');
        start++;
    }
    return (res == 0 ? 1 : res);   //  总系数不能是0啊！
}

void deal(const string& s,int e){  // 开始考虑单个字符的计算  e 是这个表达式的总系数  快慢指针处理字符串
    int i = 0, j;  // i是处理字符的起点
    e *= computenum(s, i);   // 计算总系数
    while(i < s.size()){
        if(isupper(s[i])){  // 确定是一个元素了
            if(i+1 < s.size() and islower(s[i+1])){     // 双原子元素
                int k = i;
                i += 2;  // 指向元素后面的数字
                mp[s.substr(k, 2)] += e * computenum(s,i);   // 此时 i以及指向了下一个判断位了
            }else{   // 单原子元素
                int k = i;
                i += 1;
                mp[s.substr(k, 1)] += e * computenum(s, i);
            }
        }else{    // 不是元素 开始考虑括号    其实 括号的内部 就是一个结果相同的表达式
            int left = i, right = i + 1, num = 1; // 开始寻找括号的右边界   处理区间即为[left+1,right-1]
            while(num!=0 and right < s.size()){
                if(s[right] == '(')
                    num++;
                else if(s[right] == ')')
                    num--;
                right++;
            }
            deal(s.substr(left + 1, right - left - 2), e * computenum(s, right));
            i = right;
        }
    }
}

void compute(const string& s,int exp){   // 把整个表达式进行了分割
    int i, j;
    for (i = 0; i < s.size();){
        j = s.find('+', i);
        if(j == string::npos){
            deal(s.substr(i),exp);
            i = s.size();
        }else{
            deal(s.substr(i, j - i),exp); // 第二参数是子串的长度
            i = j + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ni;
    cin >> ni;
    string s;
    while (ni--){
        cin >> s; //   要处理的化学方程式
        auto j = s.find('=');
        compute(s.substr(0, j), 1); // 计算左边
        compute(s.substr(j + 1),-1);   //  计算右边  右边要减去 参数是 -1 
        for(auto i : mp){
           if(i.second !=0){
               cout << "N\n";
               goto loop;
           }
        }
        cout << "Y\n";
        loop:;
        mp.clear();   // 图一定要清空！
   }
   return 0;
}
