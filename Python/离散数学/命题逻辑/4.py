#coding=utf-8

import sympy as sym

# 定义符号p,q。
#***** Begin *****#
p,q = sym.symbols("p,q")


#***** End *****#

# 输出析取三段论，中间逗号使用析取符号。
#***** Begin *****#
sym.pprint((~p & (p | q)) >> q)

#***** End *****#

# 按照例子验证析取三段论为重言式。
#***** Begin *****#
def fun(a):
    tt = a.subs({p:True,q:True})
    tf = a.subs({p:True,q:False})
    ft = a.subs({p:False,q:True})
    ff = a.subs({p:False,q:False})
    if tt and tf and ft and ff:
        print(True)
    else:
        print(False)
fun((~p & (p | q)) >> q)

#***** End *****#


# 判断((p -> q) ^ q) -> p 是否为重言式。
#***** Begin *****#

fun(((p >> q) & q) >> p)

#***** End *****#