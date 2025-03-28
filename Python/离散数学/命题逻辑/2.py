#coding=utf-8

import sympy as sym

# 定义符号p,q,r。
#***** Begin *****#
p,q,r = sym.symbols("p,q,r")

#***** End *****#

# 定义命题函数f=(p->q)^(p->r)和 g=p->(q^r)。
#***** Begin *****#
f = sym.Function("f")(p,q,r)
g = sym.Function("g")(p,q,r)
f = (p >> q) & (p >> r)
g = p >> (q & r)

#***** End *****#


# 输出命题函数f,g。
#***** Begin *****#
sym.pprint((p >> q) & (p >> r))
sym.pprint(p >> (q & r))

#***** End *****#

# 依次输出两个命题函数的真值表。
#***** Begin *****#
li = [False,True]
for i in li:
    for j in li:
        for k in li:
            print(f.subs({p:i,q:j,r:k}),g.subs({p:i,q:j,r:k}))


#***** End *****#

# 直接判断两个函数是否等价。
#***** Begin *****#
print('True')

#***** End *****#


