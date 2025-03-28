#coding=utf-8

import sympy as sym


# 定义符号p,q。
#***** Begin *****#
p,q = sym.symbols("p,q")

#***** End *****#

# 使用函数验证两个命题公式是否等值，输出结果
#***** Begin *****#
def fun(a,b):
    ff = a.subs({p:False,q:False}) == b.subs({p:False,q:False})
    ft = a.subs({p:False,q:True}) == b.subs({p:False,q:True})
    tf = a.subs({p:True,q:False}) == b.subs({p:True,q:False})
    tt = a.subs({p:True,q:True}) == b.subs({p:True,q:True})
    if ff and ft and tf and tt:
        print(True)
    else:
        print(False)
# fun(p>>q,~p|q)
#***** End *****#


# 将等值演算的每一步命题公式用变量stepx保存,例如step0 = p|~((~q|p)&q)
#***** Begin *****#
step0 = p|~((~q|p)&q)
step1 = p|~((~q&p)|(p&q))
step2 = p|~((False|(p&q)))
step3 = p|~(p&q)
step4 = p|(~p|~q)
step5 = (p|~p)|~q
step6 = True | ~q
step7 = True
#***** End *****#

# 使用函数fun(a,b)验证等值演算每一步。例如，fun(step0, step1)
#***** Begin *****#
fun(step0,step1)
fun(step1,step2)
fun(step2,step3)
fun(step3,step4)
fun(step4,step5)
fun(step5,step6)
#***** End *****#
