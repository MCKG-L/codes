#coding=utf-8

import sympy as sym

# 定义符号p，q，r。
#***** Begin *****#

p = sym.symbols("p")
q = sym.symbols("q")
r = sym.symbols("r")
#***** End *****#



# 输出(p->q)^r。
#***** Begin *****#

sym.pprint((p >> q) & r)

#***** End *****#


# 依次输出 (p->q)^r 的真值表。
#***** Begin *****#

li = [False,True]
print('{:10} | {:10} | {:10} | {:10}'.format('p','q','r','(p>>q) & r'))

for i in li:
    for j in li:
        for k in li:
            if i == True and j == True and k == False:
                pass
            else:
                print('{:10} | {:10} | {:10} | '.format(str(i),str(j),str(k)),end = '')
                sym.pprint(((p >> q) & r).subs({p:i, q:j, r:k}))
                
#***** End *****#
