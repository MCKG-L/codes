
#include "getsym.h"
/*getsym.h中定义了词法分析函数GETSYM()
返回值：
    if (ch == EOF) {
        return "finish";
      }
    if (isalpha(ch)) {      //ch是字母，则单词可能是标识符或者关键字
        do {
            strToken += ch;
            ch = cin.get();
        }while (isalpha(ch) || isdigit(ch));
        id = strToken;
        if (id.size() > 10) {         //关键词与标识符的大小限制为10
            error(TOOLANG);
            return "error";
        }
        bool isKey = false;
        for (int i = 0; i < 13; ++i)       //查找是否属于关键字
            if (id == keywords[i]) {
                isKey = true;
                SYM_type = i;
                break;
            }
        if (isKey) {                         //关键字的输出
            ;//print_result(SYM_type);
        }
        else {                              //标识符的输出
            SYM_type = IDE_SYM;
            insertIdentifier(id);
            //print_result<string>(SYM_type, id, insertIdentifier(id));
//#if DEBUG
            debugId = id;
//#endif
            id = "identifier";
        }
        fcin.seekg(-1,ios::cur);    //退回读取的多余的字符
        return id;
    }
    else if (isdigit(ch)) {
        int count = 0;
        do {
            strToken += ch;
            count = count * 10 + ch - '0';
            ch = cin.get();
        }while (isdigit(ch));
        if (isalpha(ch)) {
            error(WRONG_NUMBER);
            return "error";
        }
        SYM_type = NUM_SYM;
        numValue = count;
        fcin.seekg(-1,ios::cur);    //数字的输出
        insertConst(numValue);
        //print_result<int>(SYM_type, numValue, insertConst(numValue));
//#if DEBUG
        debugNum = strToken;
        debugNumber = numValue;
//#endif
        return "number";
    }
    else if (ch == '+') {
        SYM_type = ADD_SYM;
        //print_result(SYM_type);
        return "+";
    }
    else if (ch == '-') {
        SYM_type = SUB_SYM;
        //print_result(SYM_type);
        return "-";
    }
    else if (ch == '*') {
        SYM_type = MULT_SYM;
        //print_result(SYM_type);
        return "*";
    }
    else if (ch == '/') {
        SYM_type = DIV_SYM;
        //print_result(SYM_type);
        return "/";
    }
    else if (ch == '=') {
        SYM_type = EQUAL_SYM;
        //print_result(SYM_type);
        return "=";
    }
    else if (ch == '#') {
        SYM_type = NEQUAL_SYM;
        //print_result(SYM_type);
        return "#";
    }
    else if (ch == '<') {
        ch = cin.get();
        if (ch == '=') {
            SYM_type = ELESS_SYM;
            //print_result(SYM_type);
            return "<=";
        }
        else {
            SYM_type = LESS_SYM;
            //print_result(SYM_type);
            fcin.seekg(-1,ios::cur);
            return "<";
        }
    }
    else if (ch == '>') {
        ch = cin.get();
        if (ch == '=') {
            SYM_type = EGRE_SYM;
            //print_result(SYM_type);
            return ">=";
        }
        else {
            SYM_type = GRE_SYM;
            //print_result(SYM_type);
            fcin.seekg(-1, ios::cur);
            return ">";
        }
    }
    else if (ch == '(') {
        SYM_type = LEFTP_SYM;
        //print_result(SYM_type);
        return "(";
    }
    else if (ch == ')') {
        SYM_type = RIGHTP_SYM;
        //print_result(SYM_type);
        return ")";
    }
    else if (ch == '.') {
        SYM_type = DOT_SYM;
        //print_result(SYM_type);
        return ".";
    }
    else if (ch == ',') {
        SYM_type = COMMA_SYM;
        //print_result(SYM_type);
        return ",";
    }
    else if (ch == ':') {
        ch = cin.get();
        if (ch == '=') {
            SYM_type = ASSI_SYM;
            //print_result(SYM_type);
            return ":=";
        }
        else {
            error(ASSI_ERROR);
            return "error_assi_error";
        }
    }
    else if (ch == ';') {
        SYM_type = SEMICOLON_SYM;
        //print_result(SYM_type);
        return ";";
    }
    else {
        error(ANOTHER_WORD);
        return "error";
    }
    return nullptr;


*/

/*
以下全局变量由词法分析产生，在本程序中可以使用
string debugId;             //词法分析产生的标识符
string debugNum;            //词法分析产生的无符号整数的string形式
int debugNumber;            //词法分析产生的无符号整数
*/

/*定义各种语法错误*/
enum ERROR_GRAMMAR {
    const_state_end_wrong,
    number_wrong,
    const_assign_wrong,
    identifier_wrong,
    var_state_end_wrong,
    procedure_state_end_wrong,
    procedure_head_wrong,
    var_assign_wrong,
    expression_in_factor_wrong,
    if_then_wrong,
    condition_wrong,
    while_do_wrong,
    read_end_wrong,
    read_wrong,
    write_end_wrong,
    write_wrong,
    complex_end_wrong,
    wrong_program_end,
    var_undefined,
    var_redefined,
    repeat_until_missing
};

struct treeNode {
    string element;
    vector<treeNode* > child;
    explicit treeNode(string e) {
        element = e;            //NOLINT
        for (auto & it : child)
            it = nullptr;
    }
};


/*输出语法分析树*/
void printTreeNode(treeNode *root, int level)
{
    if (root != nullptr) {
        for (int i = 0; i < level; ++i)
            cout << "|  ";
        cout << ">  " << root->element << endl;
        for (auto & it : root->child)
            printTreeNode(it, level+1);
    }
}

string sym;

bool error_grammar = false;

void error_exc(int error_grammar_type);               //错误处理
void BLOCK(treeNode* tn);                   //语法分析入口程序
void subBlock(treeNode* tn);                //分程序
void const_BLOCK(treeNode* tn);             //常量说明
void const_def(treeNode* tn);               //常量定义
int var_BLOCK(treeNode* tn);               //变量说明
void procedure_BLOCK(treeNode* tn);         //过程说明
void procedure_head(treeNode* tn);          //过程首部
void sen_BLOCK(treeNode* tn);               //语句
void assi_sen(treeNode* tn);                //赋值语句
void condition_sen(treeNode* tn);           //条件语句
void do_while_sen(treeNode* tn);            //当型循环语句
void proc_call_sen(treeNode* tn);           //过程调用语句
void read_sen(treeNode* tn);                //读语句
void write_sen(treeNode* tn);               //写语句
void complex_sen(treeNode* tn);             //复合语句
void expression(treeNode* tn);              //表达式
void condition(treeNode* tn);               //条件
void item(treeNode* tn);                    //项
void factor(treeNode* tn);                  //因子
void repeat_sen(treeNode *tn);              //重复语句
void error_exc(int error_grammar_type)
{
    error_grammar = true;
    switch (error_grammar_type) {
        case const_state_end_wrong:
            cout << "常量说明结束错误 in line " << lineSum << endl;
            break;
        case number_wrong:
            cout << "无符号整数错误 in line " << lineSum << endl;
            break;
        case const_assign_wrong:
            cout << "常数赋值错误 in line " << lineSum << endl;
            break;
        case identifier_wrong:
            cout << "标识符错误 in line " << lineSum << endl;
            break;
        case var_state_end_wrong:
            cout << "变量说明结束错误 in line " << lineSum << endl;
            break;
        case procedure_state_end_wrong:
            cout << "过程说明结束错误 in line " << lineSum << endl;
            break;
        case procedure_head_wrong:
            cout << "过程首部错误 in line " << lineSum << endl;
            break;
        case var_assign_wrong:
            cout << "变量赋值错误 in line " << lineSum << endl;
            break;
        case expression_in_factor_wrong:
            cout << "因子中的表达式错误 in line " << lineSum << endl;
            break;
        case if_then_wrong:
            cout << "if_then语句错误 in line " << lineSum << endl;
            break;
        case condition_wrong:
            cout << "条件错误 in line " << lineSum << endl;
            break;
        case while_do_wrong:
            cout << "while_do语句错误 in line " << lineSum << endl;
            break;
        case read_end_wrong:
            cout << "read语句结束错误 in line " << lineSum << endl;
            break;
        case read_wrong:
            cout << "read语句错误 in line " << lineSum << endl;
            break;
        case write_end_wrong:
            cout << "write语句结束错误 in line " << lineSum << endl;
            break;
        case write_wrong:
            cout << "write语句错误 in line " << lineSum << endl;
            break;
        case complex_end_wrong:
            cout << "复合语句错误 in line " << lineSum << endl;
            break;
        case wrong_program_end:
            cout << "wrong program end" << endl;
            break;
        case var_undefined:
            cout << "有未定义的变量" << lineSum << endl;
            break;
        case var_redefined:
            cout << "重复定义的变量" << lineSum << endl;
            break;
        case repeat_until_missing:
            cout << "重复语句错误 in line " << lineSum << endl;
            break;
        default:
            break;
    }
    exit(0);
}

/*<程序> ::= <分程序>.*/
void BLOCK(treeNode* tn)
{
    sym = GETSYM();
    auto *subBlockt = new treeNode("分程序");
    tn->child.push_back(subBlockt);
    subBlock(subBlockt);
    if (sym == ".") {
        tn->child.push_back(new treeNode("."));
        sym = GETSYM();
        //
        cout << "Grammar analysis complete" << endl;
    }
    else error_exc(wrong_program_end);
}

/* <分程序> ::= [<常量说明部分>][变量说明部分>]{<过程说明部分>}<语句> */
void subBlock(treeNode* tn)
{
    if (sym == "const") {
        auto *const_BLOCKt = new treeNode("常量说明部分");
        tn->child.push_back(const_BLOCKt);
        const_BLOCK(const_BLOCKt);              //常量说明
    }
    if (sym == "var") {
        /*补充代码，“变量说明部分”语法定义*/    
        auto *var_BLOCKt = new treeNode("变量说明部分");
        tn->child.push_back(var_BLOCKt);
        var_BLOCK(var_BLOCKt);
    }
    if (sym == "procedure") {

        /*补充代码，“过程说明部分”语法定义*/
        while(sym == "procedure"){
            auto *procedure_BLOCKt = new treeNode("过程说明部分");
            tn->child.push_back(procedure_BLOCKt);
            procedure_BLOCK(procedure_BLOCKt);
        }
    }
    auto *sen_BLOCKt = new treeNode("语句");
    tn->child.push_back(sen_BLOCKt);
    //
    sen_BLOCK(sen_BLOCKt);                //语句
}

/*<常量说明部分> ::= const<常量定义>{,<常量定义>};*/
void const_BLOCK(treeNode* tn)
{
    if (sym == "const") {
        tn->child.push_back(new treeNode("const"));
        sym = GETSYM();
        auto *const_deft = new treeNode("常量定义");
        tn->child.push_back(const_deft);
        const_def(const_deft);
        while (sym == ",") {
            tn->child.push_back(new treeNode(","));
            sym = GETSYM();
            auto *const_defts = new treeNode("常量定义");
            tn->child.push_back(const_defts);
            const_def(const_defts);
        }
        if (sym == ";") {
            tn->child.push_back(new treeNode(";"));
            sym = GETSYM();
        }
        else error_exc(const_state_end_wrong);           //常量说明的错误结束
    } else return;
}

/*<常量定义> ::= <标识符>=<无符号整数>*/
void const_def(treeNode* tn)
{
    if (sym == "identifier") {
        auto *idt = new treeNode(debugId);
        tn->child.push_back(new treeNode("标识符"));
        tn->child.back()->child.push_back(idt);
        //
        sym = GETSYM();
        if (sym == "=") {
            tn->child.push_back(new treeNode("="));
            sym = GETSYM();
            if (sym == "number") {
                auto *numt = new treeNode(debugNum);
                tn->child.push_back(new treeNode("无符号整数"));
                tn->child.back()->child.push_back(numt);
                //
                sym = GETSYM();
            }
            else error_exc(number_wrong);       //不是数字
        } else error_exc(const_assign_wrong);         //不是常量赋值
    } else error_exc(identifier_wrong);             //不是标识符
}

/*<变量说明部分>::= var<标识符>{,<标识符>};*/
int var_BLOCK(treeNode* tn)
{
    if (sym == "var") {
        tn->child.push_back(new treeNode("var"));
        sym = GETSYM();

        if (sym == "identifier") {
            auto* idt = new treeNode(debugId);
            auto* idNode = new treeNode("标识符");
            idNode->child.push_back(idt);
            tn->child.push_back(idNode);

            sym = GETSYM();
            while (sym == ",") {
                tn->child.push_back(new treeNode(","));
                sym = GETSYM();

                if (sym == "identifier") {
                    auto* idt = new treeNode(debugId);
                    auto* idNode = new treeNode("标识符");
                    idNode->child.push_back(idt);
                    tn->child.push_back(idNode);

                    sym = GETSYM();
                } else {
                    error_exc(identifier_wrong);
                    return -1;
                }
            }

            if (sym == ";") {
                tn->child.push_back(new treeNode(";"));
                sym = GETSYM();
                return 0;  // 成功
            } else {
                error_exc(var_state_end_wrong);  // 缺少分号
                return -1;
            }
        } else {
            error_exc(identifier_wrong);  // var 后不是标识符
            return -1;
        }
    }
    return -1;  // 不是变量声明部分，留给上层判断
}


/*<过程说明部分> ::= <过程首部><分程序>；*/
void procedure_BLOCK(treeNode* tn)
{
    if (sym == "procedure") {
        auto *procedure_headt = new treeNode("过程首部");
        tn->child.push_back(procedure_headt);
        procedure_head(procedure_headt);
        auto *subBlockt = new treeNode("分程序");
        tn->child.push_back(subBlockt);
        subBlock(subBlockt);
        if (sym == ";") {
            tn->child.push_back(new treeNode(";"));
            sym = GETSYM();
            while (sym == "procedure") {
                auto *procedure_BLOCKt = new treeNode("过程说明部分");
                tn->child.push_back(procedure_BLOCKt);
                procedure_BLOCK(procedure_BLOCKt);
            }
        }
        else error_exc(procedure_state_end_wrong);           //过程说明的结束错误
    } else return;
}
/* <过程首部> ::= procedure<标识符>; */
void procedure_head(treeNode* tn)
{
    //补充代码，完成“过程首部”语法定义
    if(sym == "procedure"){
        tn->child.push_back(new treeNode("procedure"));
        sym = GETSYM();

        if(sym == "identifier"){
            auto *idt = new treeNode(debugId);
            tn->child.push_back(new treeNode("标识符"));
            tn->child.back()->child.push_back(idt);
            //
            sym = GETSYM();
            if (sym == ";") {
                tn->child.push_back(new treeNode(";"));
                sym = GETSYM();
            }
            else error_exc(procedure_head_wrong);
        }else error_exc(identifier_wrong);
    }else return;

}
/*
<语句> ::= <赋值语句>|<条件语句>|<当型循环语句>|<过程调用语句>|<读语句>|<写语句>|<复合语句>|<重复语句>|<空>
（重复语句）选做
 */
/* 包含重复语句的测试
const a = 3;
var x, y;
begin
    x := a;
    y := 0;
    repeat
        y := y + 1;
        x := x - 1
    until x = 0;
    write(y)
end.
*/
void sen_BLOCK(treeNode* tn)
{
    if (sym == "identifier") {
        auto *assi_sent = new treeNode("赋值语句");
        tn->child.push_back(assi_sent);
        assi_sen(assi_sent);
    }
    else if (sym == "if") {
        auto *condition_sent = new treeNode("条件语句");
        tn->child.push_back(condition_sent);
        condition_sen(condition_sent);
    }
    else if (sym == "while") {
        auto *do_while_sent = new treeNode("当型循环语句");
        tn->child.push_back(do_while_sent);
        do_while_sen(do_while_sent);
    }
    else if (sym == "call") {
        auto *proc_call_sent = new treeNode("过程调用语句");
        tn->child.push_back(proc_call_sent);
        proc_call_sen(proc_call_sent);
    }
    else if (sym == "read") {
        auto *read_sent = new treeNode("读语句");
        tn->child.push_back(read_sent);
        read_sen(read_sent);
    }
    else if (sym == "write") {
        auto *write_sent = new treeNode("写语句");
        tn->child.push_back(write_sent);
        write_sen(write_sent);
    }
    else if (sym == "begin") {
        auto *complex_sent = new treeNode("复合语句");
        tn->child.push_back(complex_sent);
        complex_sen(complex_sent);
    }else if (sym == "repeat") {
        // cerr << "repeat" << endl;
        auto *repeat_sent = new treeNode("重复语句");
        tn->child.push_back(repeat_sent);
        repeat_sen(repeat_sent);
    }
}
/* <重复语句> ::= repeat <语句> {; <语句>} until <条件> */
void repeat_sen(treeNode* tn)
{
    if (sym == "repeat") {
        tn->child.push_back(new treeNode("repeat"));
        sym = GETSYM();
        // 至少一个语句
        auto *stmt = new treeNode("语句");
        tn->child.push_back(stmt);
        sen_BLOCK(stmt);

        // 重复 ; <语句>
        while (sym == ";") {
            tn->child.push_back(new treeNode(";"));
            sym = GETSYM();
            auto *stmt_more = new treeNode("语句");
            tn->child.push_back(stmt_more);
            sen_BLOCK(stmt_more);
        }
        if (sym == "until") {
            tn->child.push_back(new treeNode("until"));
            sym = GETSYM();

            auto *cond = new treeNode("条件");
            tn->child.push_back(cond);
            condition(cond);
        } else {
            error_exc(repeat_until_missing);  // 你可以自定义该错误类型
        }
    }
}

/*<赋值语句> ::= <标识符>:=<表达式>*/
void assi_sen(treeNode* tn)
{
    if (sym == "identifier") {
        auto *idt = new treeNode(debugId);
        tn->child.push_back(new treeNode("标识符"));
        tn->child.back()->child.push_back(idt);
        string tmp = debugId;       //保存待赋值的变量
        sym = GETSYM();
        if (sym == ":=") {
            tn->child.push_back(new treeNode(":="));
            sym = GETSYM();
            auto *expressiont = new treeNode("表达式");
            tn->child.push_back(expressiont);
            expression(expressiont);

            //
        } else error_exc(var_assign_wrong);         //不是变量赋值
    } else return;
}
/*
<表达式> ::= [+|-]<项>{<加法运算符><项>}
*/
void expression(treeNode* tn)
{
    if (sym == "+" || sym == "-") {
        // tn->child.push_back(new treeNode("加减运算符"));
        tn->child.push_back(new treeNode(sym));
        sym = GETSYM();
    }

    auto *itemt = new treeNode("项");
    tn->child.push_back(itemt);
    item(itemt);

    while (sym == "+" || sym == "-") {
        tn->child.push_back(new treeNode("加减运算符"));
        tn->child.back()->child.push_back(new treeNode(sym));
        sym = GETSYM();
        auto *itemNext = new treeNode("项");
        tn->child.push_back(itemNext);
        item(itemNext);
    }
}
/*
<项> ::= <因子>{<乘法运算符><因子>}
*/
void item(treeNode* tn)
{
    auto *factort = new treeNode("因子");
    tn->child.push_back(factort);
    factor(factort);

    while (sym == "*" || sym == "/") {
        tn->child.push_back(new treeNode("乘除运算符"));
        tn->child.back()->child.push_back(new treeNode(sym));  // 乘法运算符
        sym = GETSYM();
        auto *factorNext = new treeNode("因子");
        tn->child.push_back(factorNext);
        factor(factorNext);
    }
}

/*
<因子> ::= <标识符>|<无符号整数>|'('<表达式>')'
*/
void factor(treeNode* tn)
{
    if (sym == "identifier" || sym == "number") {
        string tmp;
        treeNode *idt;
        if (sym == "identifier") {
            tmp = "标识符";
            idt = new treeNode(debugId);
        }
        else {
            tmp = "无符号整数";
            idt = new treeNode(debugNum);

        }
        tn->child.push_back(new treeNode(tmp));
        tn->child.back()->child.push_back(idt);
        sym = GETSYM();
    }
    else if (sym == "(") {
        tn->child.push_back(new treeNode("("));
        sym = GETSYM();
        auto *expressiont = new treeNode("表达式");
        tn->child.push_back(expressiont);
        expression(expressiont);
        if (sym == ")") {
            tn->child.push_back(new treeNode(")"));
            sym = GETSYM();
        }
        else cout<<"error";           //因子中包含的表达式的错误结束
    }
    else return;
}
/*
<条件语句> ::= if<条件>then<语句>[else<语句>]
注意：else部分选做
*/
void condition_sen(treeNode* tn)
{
    //补充代码，完成“条件语句”语法定义
    if(sym == "if"){
        tn->child.push_back(new treeNode("if"));
        sym = GETSYM();
        auto *conditiont = new treeNode("条件");
        tn->child.push_back(conditiont);
        condition(conditiont);
        if(sym == "then"){
            tn->child.push_back(new treeNode("then"));
            sym = GETSYM();
            auto *sen_BLOCKt = new treeNode("语句");
            tn->child.push_back(sen_BLOCKt);
            sen_BLOCK(sen_BLOCKt);
        }else error_exc(if_then_wrong);
        if(sym == "else"){
            tn->child.push_back(new treeNode("else"));
            sym = GETSYM();
            auto *sen_BLOCKt = new treeNode("语句");
            tn->child.push_back(sen_BLOCKt);
            sen_BLOCK(sen_BLOCKt);
        }
    }else return;
}
/*
<条件> ::= <表达式><关系运算符><表达式>|odd<表达式>
<关系运算符> ::= =|<>|<|<=|>|>=
*/
void condition(treeNode* tn)
{
    if (sym != "odd") {
        auto *expressiont0 = new treeNode("表达式");
        tn->child.push_back(expressiont0);
        expression(expressiont0);
        if (sym == "=" || sym == "#" || sym == "<" || sym == "<=" || sym == ">" || sym == ">=") {
            string opr = sym;
            auto *idt = new treeNode(sym);
            tn->child.push_back(new treeNode("条件运算符"));
            tn->child.back()->child.push_back(idt);
            sym = GETSYM();
            auto *expressiont1 = new treeNode("表达式");
            tn->child.push_back(expressiont1);
            expression(expressiont1);

        } else error_exc(condition_wrong);         //不是正确的条件符
    }
    else {
        string opr = sym;
        tn->child.push_back(new treeNode("odd"));
        sym = GETSYM();
        auto *expressiont2 = new treeNode("表达式");
        tn->child.push_back(expressiont2);
        expression(expressiont2);
    }
}

/*
<过程调用语句> ::= call<标识符>
*/
void proc_call_sen(treeNode* tn)
{
    if (sym == "call") {
        tn->child.push_back(new treeNode("call"));
        sym = GETSYM();
        if (sym == "identifier") {
            auto *idt = new treeNode(debugId);
            tn->child.push_back(new treeNode("标识符"));
            tn->child.back()->child.push_back(idt);

            sym = GETSYM();
        }
        else error_exc(identifier_wrong);           //不是标识符
    } else return;
}
void do_while_sen(treeNode* tn)
{
    if (sym == "while") {
        tn->child.push_back(new treeNode("while"));
        sym = GETSYM();
        auto *conditiont = new treeNode("条件");
        tn->child.push_back(conditiont);
        condition(conditiont);
        if (sym == "do") {
            tn->child.push_back(new treeNode("do"));
            sym = GETSYM();
            auto *sen_BLOCKt = new treeNode("语句");
            tn->child.push_back(sen_BLOCKt);

            sen_BLOCK(sen_BLOCKt);

        } else error_exc(while_do_wrong);         //不是正确的while_do语句
    } else return;
}

/*
<读语句> ::= read'('<标识符>{,<标识符>}')'
*/
void read_sen(treeNode* tn)
{
    if (sym == "read") {
        tn->child.push_back(new treeNode("read"));

        sym = GETSYM();
        if (sym == "(") {
            tn->child.push_back(new treeNode("("));
            sym = GETSYM();
            if (sym == "identifier") {
                auto *idt = new treeNode(debugId);
                tn->child.push_back(new treeNode("标识符"));
                tn->child.back()->child.push_back(idt);

                sym = GETSYM();
            }
            else error_exc(identifier_wrong);       //不是标识符
            while (sym == ",") {
                tn->child.push_back(new treeNode(","));

                sym = GETSYM();
                if (sym == "identifier") {
                    auto *idt = new treeNode(debugId);
                    tn->child.push_back(new treeNode("标识符"));
                    tn->child.back()->child.push_back(idt);

                    sym = GETSYM();
                }
            }
            if (sym == ")") {
                tn->child.push_back(new treeNode(")"));
                sym = GETSYM();
            }
            else error_exc(read_end_wrong);       //不是正确的read语句结束
        } else error_exc(read_wrong);         //不是正确的read语句
    } else return;
}

/*
<写语句> ::= write'('<标识符>{,<标识符>}')'
*/
void write_sen(treeNode* tn)
{
    if (sym == "write") {
        tn->child.push_back(new treeNode("write"));
        sym = GETSYM();
        if (sym == "(") {
            tn->child.push_back(new treeNode("("));
            sym = GETSYM();
            auto *expressiont = new treeNode("表达式");
            tn->child.push_back(expressiont);
            expression(expressiont);

            while (sym == ",") {
                tn->child.push_back(new treeNode(","));
                sym = GETSYM();
                auto *expressionts = new treeNode("表达式");
                tn->child.push_back(expressionts);
                expression(expressionts);

            }
            if (sym == ")") {
                tn->child.push_back(new treeNode(")"));
                sym = GETSYM();
            }
            else error_exc(write_end_wrong);       //不是正确的write语句结束
        } else error_exc(write_wrong);         //不是正确的write语句
    } else return;
}

/*
<复合语句> ::= begin<语句>{;<语句>}end
*/
void complex_sen(treeNode* tn)
{
    if (sym == "begin") {
        tn->child.push_back(new treeNode("begin"));
        sym = GETSYM();
        auto *sen_BLOCKt = new treeNode("语句");
        tn->child.push_back(sen_BLOCKt);
        sen_BLOCK(sen_BLOCKt);
        while (sym == ";") {
            tn->child.push_back(new treeNode(";"));
            sym = GETSYM();
            auto *sen_BLOCKts = new treeNode("语句");
            tn->child.push_back(sen_BLOCKts);
            sen_BLOCK(sen_BLOCKts);
        }
        if (sym == "end") {
            tn->child.push_back(new treeNode("end"));
            sym = GETSYM();
        }
        else error_exc(complex_end_wrong);           //不是正确的复合语句结束
    } else return;
}
int main() {
    auto* BLOCKT = new treeNode("程序");

    while (sym != "finish" && sym != "error") {
        BLOCK(BLOCKT);
        // BLOCK 里一般包含了对 getSym() 的调用来推进 token 流
        // 如果你没有在 BLOCK 内调用 getSym()，可以在这里手动调用
        // getSym();
    }

    if (!error_grammar) {
        printTreeNode(BLOCKT, 0);
    }

    return 0;
}
// int main() {
// //	freopen("D:\\Others\\desktop\\text.in","r",stdin);
//     string fileinname = "课程实验及作业\\编译原理\\实验二\\test.txt";
    
//     // cin >> fileinname;
//     streambuf *stdin_backup = cin.rdbuf();         //备份标准输入流
//     fcin.open(fileinname);
//     if (!fcin.is_open()) {
//         cout << "failed to open " << fileinname << endl;
//         cin.get();
//         return 0;
//     }
//     cin.rdbuf(fcin.rdbuf());                //将cin重定向到文件
//     auto *BLOCKT = new treeNode("程序");
//     while (fcin.tellg() != ios::end) {
//         BLOCK(BLOCKT);
//         if (sym == "finish" || sym == "error")
//             break;
//     }
//     if (!error_grammar) {
//         printTreeNode(BLOCKT, 0);
//     }
//     cin.rdbuf(stdin_backup);
//     fcin.close(); 
//     return 0;
// }
