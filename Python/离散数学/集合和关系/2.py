#coding=utf-8

import sympy as sym

# 创建有限集A和B,A包含元素1-5，B包含元素2,3,5,7。
#***** Begin *****#
A = sym.FiniteSet(1,2,3,4,5)
B = sym.FiniteSet(2,3,5,7)
#***** End *****#

# 打印A，B两个集合。
#***** Begin *****#
print(A)
print(B)
#***** End *****#


# 输出A, B的交集。
#***** Begin *****#
C = sym.Intersection(A,B)
print(C)
#***** End *****#

# 输出A, B的并集。
#***** Begin *****#
C = sym.Union(A,B)
print(C)
#***** End *****#

# 输出A, B的差集。
#***** Begin *****#
C = A - B
print(C)

#***** End *****#

# 验证A-B与A-A交B是否相等。
#***** Begin *****#
C = A - B
D = A - sym.Intersection(A,B)
print(C == D)
#***** End *****#


# 验证A,B的对称差与(A-B)并(B-A)是否相等
#***** Begin *****#
C = sym.Union(A,B) - sym.Intersection(A,B)
D = sym.Union(A-B,B-A)
print(C == D)
#***** End *****#

