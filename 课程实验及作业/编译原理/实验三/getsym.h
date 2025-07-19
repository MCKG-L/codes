//#ifndef RUN_PL0_GETSYM_H
//#define RUN_PL0_GETSYM_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<int> integerArray;
vector<string> identifierArray;
const string keywords[16] = {"const", "var", "procedure", "begin", "end", "odd",//NOLINT
                             "if", "then", "call", "while", "do", "read", "write","repeat","until","else"};
int lineSum = 0;       //记录源程序的行数，用于出错处理
ifstream fcin;         //打开文件NOLINT
int SYM_type;
int numValue = 0;
string id;
//#if DEBUG
string debugId;             //词法分析产生的标识符
string debugNum;            //词法分析产生的无符号整数的string形式
int debugNumber;            //词法分析产生的无符号整数
//#endif

enum SYM_class {
    //关键字
    CONST_SYM,              //const
    VAR_SYM,                //var
    PROCEDURE_SYM,          //procedure
    BEGIN_SYM,              //begin
    END_SYM,                //end
    ODD_SYM,                //odd
    IF_SYM,                 //if
    THEN_SYM,               //then
    CALL_SYM,               //call
    WHILE_SYM,              //while
    DO_SYM,                 //do
    READ_SYM,               //read
    WRITE_SYM,              //write
    REPEAT_SYM,             //repeat (补充)
    UNTIL_SYM,              //until (补充)
    ELSE_SYM,                //else (补充)
    //算符与界符
    ADD_SYM,                // +
    SUB_SYM,                // -
    MULT_SYM,               // *
    DIV_SYM,                // /
    EQUAL_SYM,              // =
    NEQUAL_SYM,             // #
    LESS_SYM,               // <
    ELESS_SYM,              // <=
    GRE_SYM,                // >
    EGRE_SYM,               // >=
    LEFTP_SYM,              // (
    RIGHTP_SYM,             // )
    DOT_SYM,                // .
    COMMA_SYM,              // ,
    ASSI_SYM,               // :=
    SEMICOLON_SYM,          // ;
    NUM_SYM,                //数字
    IDE_SYM                 //标识符
};

enum ERROR_CODE {
    TOOLANG,
    ASSI_ERROR,
    ANOTHER_WORD,
    WRONG_NUMBER
};

int insertIdentifier(const string& str)      //插入到标识符符号表
{
    int location = 0;
    auto itd = identifierArray.begin();
    for (; itd != identifierArray.end(); ++itd) {
        if (*itd == str)
            break;
        location++;
    }
    if (itd == identifierArray.end()) {
        identifierArray.push_back(str);
        return location;
    }
    else
        return location;
}

int insertConst(int number)   //插入到常数表
{
    //补全代码
    int location = 0;
    auto itd = integerArray.begin();
    for (; itd != integerArray.end(); ++itd) {
        if (*itd == number)
            break;
        location++;
    }
    if (itd == integerArray.end()) {
        integerArray.push_back(number);
        return location;
    }
    else
        return location;
}
int error(int ERROR_CODE_TYPE) {  //NOLINT
	return -1; 
    switch (ERROR_CODE_TYPE) {
        case TOOLANG:
            cout << "Identifier " << id << " in line " << lineSum << " is too long" << endl;
            break;
        case ASSI_ERROR:
            cout << "wrong assignment in line " << lineSum << endl;
            break;
        case ANOTHER_WORD:
            cout << "wrong words in line " << lineSum << endl;
            break;
        case WRONG_NUMBER:
            cout << "wrong number in line " << lineSum << endl;
            break;
        default:
            break;
    }
    return -1;
}

template<class T>
void print_result(int sym, T name,  int value)
{
	return;
    switch (sym) {
        case NUM_SYM:
            cout << "( number," << name << "," << value << " )" << endl;
            break;
        case IDE_SYM:
            cout << "( identifier," << name << "," << value << " )" << endl;
            break;
        default:
            break;
    }
}

void print_result(int sym)
{
	return;
    switch (sym) {
        case CONST_SYM:
            cout << "( 'const',- )" << endl;
            break;
        case VAR_SYM:
            cout << "( 'var',- )" << endl;
            break;
        case PROCEDURE_SYM:
            cout << "( 'procedure',- )" << endl;
            break;
        case BEGIN_SYM:
            cout << "( 'begin',- )" << endl;
            break;
        case END_SYM:
            cout << "( 'end',- )" << endl;
            break;
        case ODD_SYM:
            cout << "( 'odd',- )" << endl;
            break;
        case IF_SYM:
            cout << "( 'if',- )" << endl;
            break;
        case THEN_SYM:
            cout << "( 'then',- )" << endl;
            break;
        case CALL_SYM:
            cout << "( 'call',- )" << endl;
            break;
        case WHILE_SYM:
            cout << "( 'while',- )" << endl;
            break;
        case DO_SYM:
            cout << "( 'do',- )" << endl;
            break;
        case READ_SYM:
            cout << "( 'read',- )" << endl;
            break;
        case WRITE_SYM:
            cout << "( 'write',- )" << endl;
            break;
        case ADD_SYM:
            cout << "( '+',- )" << endl;
            break;
        case SUB_SYM:
            cout << "( '-',- )" << endl;
            break;
        case MULT_SYM:
            cout << "( '*',- )" << endl;
            break;
        case DIV_SYM:
            cout << "( '/',- )" << endl;
            break;
        case EQUAL_SYM:
            cout << "( '=',- )" << endl;
            break;
        case NEQUAL_SYM:
            cout << "( '#',- )" << endl;
            break;
        case LESS_SYM:
            cout << "( '<',- )" << endl;
            break;
        case ELESS_SYM:
            cout << "( '<=',- )" << endl;
            break;
        case GRE_SYM:
            cout << "( '>',- )" << endl;
            break;
        case EGRE_SYM:
            cout << "( '>=',- )" << endl;
            break;
        case LEFTP_SYM:
            cout << "( '(',- )" << endl;
            break;
        case RIGHTP_SYM:
            cout << "( ')',- )" << endl;
            break;
        case DOT_SYM:
            cout << "( '.',- )" << endl;
            break;
        case COMMA_SYM:
            cout << "( ',',- )" << endl;
            break;
        case ASSI_SYM:
            cout << "( ':=',- )" << endl;
            break;
        case SEMICOLON_SYM:
            cout << "( ';',- )" << endl;
            break;
        default:
            break;
    }
}

string GETSYM()
{
    string strToken;        //存放构成单词的字符串
    strToken = "";
    char ch;                //存放最新读进的源程序字符
    ch = cin.get();
    while(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
        if (ch == '\n')
            lineSum++;
        ch = cin.get();
    }                       //过滤空格、tab、换行符，并对换行符进行统计，以便于定位出错位置。
    if (ch == '$') {
        return "finish";
    }
    if (isalpha(ch)) {      //ch是字母，则单词可能是标识符或者关键字
        //此处补全单词的获取
        while(isalpha(ch) || isdigit(ch)){
            strToken += ch;
            ch = cin.get();
        }
        //
        id = strToken;
        if (id.size() > 10) {         //关键词与标识符的大小限制为10
            error(TOOLANG);
            return "error";
        }
        bool isKey = false;
       //此处补全代码，查找是否属于关键字，找出关键字的编码
        int pos;
        for(int i=0;i<16;i++){
            if(keywords[i] == strToken){
                pos = i;
                isKey = true;
                if(i == 0) SYM_type = CONST_SYM;
                if(i == 1) SYM_type = VAR_SYM;
                if(i == 2) SYM_type = PROCEDURE_SYM;
                if(i == 3) SYM_type = BEGIN_SYM;
                if(i == 4) SYM_type = END_SYM;
                if(i == 5) SYM_type = ODD_SYM;
                if(i == 6) SYM_type = IF_SYM;
                if(i == 7) SYM_type = THEN_SYM;
                if(i == 8) SYM_type = CALL_SYM;
                if(i == 9) SYM_type = WHILE_SYM;
                if(i == 10) SYM_type = DO_SYM;
                if(i == 11) SYM_type = READ_SYM;
                if(i == 12) SYM_type = WRITE_SYM;
                if(i == 13) SYM_type = REPEAT_SYM;
                if(i == 14) SYM_type = UNTIL_SYM;
                if(i == 15) SYM_type = ELSE_SYM;
                break;
            }
        }
        if (isKey) {         
            // print_result(SYM_type); //关键字的输出
            // cout << "返回: " << keywords[pos] << endl;
            // return keywords[pos];
        }
        else { //标识符的输出
            SYM_type = IDE_SYM;
            insertIdentifier(id);
            // print_result<string>(SYM_type, id, insertIdentifier(id));
//#if DEBUG
            debugId = id;
//#endif
            id = "identifier";
        }
        cin.putback(ch);//退回读取的多余的字符
        return id;
    }
    else if (isdigit(ch)) {
        int count = 0;
        do {
            strToken += ch;
            //此处补全代码，用count表示单词的整形常数值
            count = count * 10 + ch - '0';
             //
            ch = cin.get();
        }while (isdigit(ch));
        if (isalpha(ch)) {
            error(WRONG_NUMBER);
            return "error";
        }
        SYM_type = NUM_SYM;
        numValue = count;
        cin.putback(ch);   
        insertConst(numValue);//数字的输出
        // print_result<int>(SYM_type, numValue, insertConst(numValue));
//#if DEBUG
        debugNum = strToken;
        debugNumber = numValue;
//#endif
        return "number";
    }else if(ch == '='){
        SYM_type = EQUAL_SYM;
        // print_result(SYM_type);
        return "=";
    }else if(ch == '('){
        SYM_type = LEFTP_SYM;
        // print_result(SYM_type);
        return "(";
    }else if(ch == ')'){
        SYM_type = RIGHTP_SYM;
        // print_result(SYM_type);
        return ")";
    }else if(ch == '+'){
        SYM_type = ADD_SYM;
        // print_result(SYM_type);
        return "+";
    }else if(ch == '-'){
        SYM_type = SUB_SYM;
        // print_result(SYM_type);
        return "-";
    }else if(ch == '*'){
        SYM_type = MULT_SYM;
        // print_result(SYM_type);
        return "*";
    }else if(ch == '/'){
        SYM_type = DIV_SYM;
        // print_result(SYM_type);
        return "/";
    }else if(ch == '.'){
        SYM_type = DOT_SYM;
        // print_result(SYM_type);
        return ".";
    }else if(ch == ','){
        SYM_type = COMMA_SYM;
        // print_result(SYM_type);
        return ",";
    }else if(ch == '#'){
        SYM_type = NEQUAL_SYM;
        // print_result(SYM_type);
        return "#";
    }
    else if(ch == '<'){
        ch = cin.get();
        if(ch == '='){
            SYM_type = ELESS_SYM;
            // print_result(SYM_type);
            return "<=";
        }else{
            SYM_type = LESS_SYM;
            // print_result(SYM_type);
            cin.putback(ch);
            return "<";
        }
    }else if(ch == '>'){
        ch = cin.get();
        if(ch == '='){
            SYM_type = EGRE_SYM;
            // print_result(SYM_type);
            return ">=";
        }else{
            SYM_type = GRE_SYM;
            // print_result(SYM_type);
            cin.putback(ch);
            return ">";
        }
    }
    //
    else if (ch == ':') {
        ch = cin.get();
        if (ch == '=') {
            SYM_type = ASSI_SYM;
            // print_result(SYM_type);
            return ":=";
        }
        else {
            // error(ASSI_ERROR);
            return "error_assi_error";
        }
    }
    else if (ch == ';') {
        SYM_type = SEMICOLON_SYM;
        // print_result(SYM_type);
        return ";";
    }
    else {
        error(ANOTHER_WORD);
        return "error";
    }
    return nullptr;
}
