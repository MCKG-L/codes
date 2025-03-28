#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;
const int N = 10010;
typedef pair<int,int> PII;
enum Status{OK = 1,ERROR = 0,OVERFLOW = -1};
//二叉链表表示
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//哈夫曼树 构造过程
//字符频率 a - z --> 0 - 25
int fre[] = {64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1, 168};
int weight[N],lchild[N],rchild[N],parent[N],idx = 1;
int root;//树根
//建树1
void CreatBiTree(BiTree &T,int u,int k){
    if(u == 0){
        T = NULL;
        return;
    }
    T = new BiTNode;
    T->data = k;
    CreatBiTree(T->lchild,lchild[u],0);
    CreatBiTree(T->rchild,rchild[u],1);
}
//创建Huffman树
void CreatHuffman(BiTree &T,int n = 27){
    //首先初始化 1-n
    for(int i=1;i<=n;i++){
        weight[idx++] = fre[i-1];
    }
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    for(int i=1;i<=n;i++){
        heap.push({weight[i],i});
    }
    while(heap.size() > 1){
        PII x1 = heap.top();heap.pop();//最小
        PII x2 = heap.top();heap.pop();//次小
        heap.push({x1.first+x2.first,idx});//新的根
        //修改
        int id1 = x1.second,id2 = x2.second;
        parent[id1] = parent[id2] = idx;
        lchild[idx] = id1;rchild[idx] = id2;
        idx ++;
    }
    root = idx - 1;
    //从树根开始创建二叉树
    CreatBiTree(T,root,0);
}
//记录哈夫曼编码
int code[30],id = 0;
vector<string> codes;
void GetCodes(BiTree T){
    if(T->lchild == NULL && T->rchild == NULL){ //叶子结点
        string s = "";
        for(int i=0;i<id;i++){
            s += '0' + code[i];
        }
        codes.push_back(s);
        return;
    }
    BiTNode *lchild = T->lchild;
    if(lchild){
        code[id++] = lchild->data;
        GetCodes(lchild);
        id --;
    }
    BiTNode *rchild = T->rchild;
    if(rchild){
        code[id++] = rchild->data;
        GetCodes(rchild);
        id --;
    }
}
//字符 -> 编码
unordered_map<char,string> encode;
//编码 -> 字符
unordered_map<string,char> decode;
void process(){
    sort(codes.begin(),codes.end(),[&](string s1,string s2){
        if(s1.size() != s2.size()) return s1.size() > s2.size();
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]) return s1[i] > s2[i];
        }
        return true;
    });
    vector<PII> freq(27);
    for(int i=0;i<27;i++){
        freq[i] = make_pair(fre[i],i);
    }
    sort(freq.begin(),freq.end());
    for(int i=0;i<27;i++){
        PII t = freq[i];
        if(i == 26){
            encode[' '] = codes[i];
            decode[codes[i]] = ' ';
        }
        else{
            encode['a'+t.second] = codes[i];
            decode[codes[i]] = 'a' + t.second;
        }
    }
    //编码-解码
    // for(int i=0;i<27;i++){
    //     if(i == 26) cout << ' ' << ": " << encode[' '] << endl;
    //     else cout << (char)(i + 'a') << ": " << encode[i + 'a'] << endl;
    // }
}
//对字符串进行编码得到编码
Status Encode(string s,string &res){
    res = "";
    for(int i=0;i<s.size();i++){
        if(!encode.count(s[i])){
            res = "";
            return ERROR;
        }
        res += encode[s[i]];
    }
    return OK;
}
//对编码进行解码得到明文字符串
Status Decode(BiTree &T,string s,string &res){
    res = "";
    BiTree p = T;
    string strcode = "";
    for(int i=0;i<s.size();i++){
        strcode += s[i];
        if(s[i] == '0'){
            p = p->lchild;
        }else{
            p = p->rchild;
        }
        if(p->lchild == NULL && p->rchild == NULL){
            if(!decode.count(strcode)){
                res = "";
                return ERROR;
            }
            res += decode[strcode];
            strcode = "";
            p = T;
        }
    }
    return OK;
}
//初始化操作 包括创建Huffman树和字符编码
void inite(BiTree &T){
    CreatHuffman(T);
    GetCodes(T);
    process();
}
void show_help(){
    cout << "***************************************" << endl;
    cout << "*******1、创建HuffmanTree**************" << endl;
    cout << "*******2、输出编码表*******************" << endl;
    cout << "*******3、输入字符串，实现编码*********" << endl;
    cout << "*******4、输入编码，翻译为字符串*******" << endl;
    cout << "*******5、退出*************************" << endl;
    cout << "***************************************" << endl;
}
int main()
{
    BiTree T = NULL;
    //得到haffuman编码值
    show_help();
    string op;
    cout << "请输入操作码：";
    while(cin >> op){
        if(op == "1"){
            inite(T);
            cout << "创建成功！" << endl;
        }else if(op == "2"){
        	if(T == NULL){
                cout << "请先创建Huffman树！" << endl;
                cout << "请输入操作码：";
                continue;
            }
            for(int i=0;i<27;i++){
                if(i == 26) cout << ' ' << ": " << encode[' '] << endl;
                else cout << (char)(i + 'a') << ": " << encode[i + 'a'] << endl;
            }
        }else if(op == "3"){
            if(T == NULL){
                cout << "请先创建Huffman树！" << endl;
                cout << "请输入操作码：";
                continue;
            }
            getchar();
            cout << "请输入字符串：";
            string s;getline(cin,s);
            if(s.size() == 0){
                cout << "请输入非空字符串！" << endl;
                cout << "请输入操作码：";
                continue;
            }
            string res = "";
            if(Encode(s,res)){
                cout << "\"" << s << "\"" << "的编码结果为：" << res << endl;    
            }else{
                cout << "您输入了非法字符！" << endl;
            }
        }else if(op == "4"){
            if(T == NULL){
                cout << "请先创建Huffman树！" << endl;
                cout << "请输入操作码：";
                continue;
            }
            getchar();
            cout << "请输入编码串：";
            string s;getline(cin,s);
            if(s.size() == 0){
                cout << "请输入非空编码串！" << endl;
                cout << "请输入操作码：";
                continue;
            }
            string res = "";
            if(Decode(T,s,res)){
                cout << s << " 对应的明文为：" <<  "\"" << res <<  "\"" << endl;
            }else{
                cout << "您输入的编码串有误！" << endl;
            }
        }else if(op == "5"){
            break;
        }else{
            cout << "操作码错误！" << endl;
        }
        cout << "请输入操作码：";
    }

    return 0;
}