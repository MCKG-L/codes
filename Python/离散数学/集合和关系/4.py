#coding=utf-8

import sympy as sym

# 定义符号a-f。
#***** Begin *****#
a,b,c,d,e,f = sym.symbols("a,b,c,d,e,f")

#***** End *****#

# 创建有限集A和B,A包含元素1,2,3，B包含元素a,b,c。
#***** Begin *****#
A = sym.FiniteSet(1,2,3)
B = sym.FiniteSet(a,b,c)
#***** End *****#

# 打印A，B两个集合。
#***** Begin *****#
print(A)
print(B)
#***** End *****#


# 输出集合A,B的笛卡儿积。
#***** Begin *****#
AxB = sym.cartes(A,B)
for i in AxB:
    print(i)

#***** End *****#

# 输出集合B,A的笛卡儿积。
#***** Begin *****#
BxA = sym.cartes(B,A)
for i in BxA:
    print(i)

#***** End *****#


# 设集合A={1，2，3}, B={a,b,c}, C={d,e,f}, R={<1,b>,<3,c>}, S={<b,f>},
# 使用关系矩阵计算R·S，输出结果矩阵。
#***** Begin *****#
R = sym.Matrix([[0,1,0],[0,0,0],[0,0,1]])
S = sym.Matrix([[0,0,0],[0,0,1],[0,0,0]])
R_S = R * S
sym.pprint(R_S)
#***** End *****#


