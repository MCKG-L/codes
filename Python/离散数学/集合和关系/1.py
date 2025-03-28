#coding=utf-8
import sympy as sym

# 定义符号a-h。
#***** Begin *****#
a,b,c,d,e,f,g,h = sym.symbols("a,b,c,d,e,f,g,h")

#***** End *****#

# 创建有限集A和B,A包含元素a-d，B包含元素e-h。
#***** Begin *****#
A = sym.FiniteSet(a,b,c,d)
B = sym.FiniteSet(e,f,g,h)

#***** End *****#

# 打印A，B两个集合。
#***** Begin *****#
print(A)
print(B)
#***** End *****#


# 判断元素a 是否在集合A中, 输出判断结果。
#***** Begin *****#
print(A.has(a))

#***** End *****#

# 判断元素a 是否在集合B中，输出判断结果。
#***** Begin *****#
print(B.has(a))

#***** End *****#


# 创建并输出集合C，C包含10以内的偶数。
#***** Begin *****#
C = sym.FiniteSet(2,4,6,8,10)
print(C)
#***** End *****#

# 创建并输出空集D。
#***** Begin *****#
D = sym.FiniteSet()
print(D)

#***** End *****#


# 按照相关知识中子集的第一个形式来验证子集的第四个性质。
#***** Begin *****#
A1 = sym.FiniteSet(1,2)
B1 = sym.FiniteSet(1,2,3)
C1 = sym.FiniteSet(1,2,3,4)
print(A1 < B1)
print(B1 < C1)
print(A1 < C1)

#***** End *****#