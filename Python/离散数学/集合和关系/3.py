#coding=utf-8

import sympy as sym


# 创建有限集A,B和C,A包含元素1-4，B包含元素3-6，C包含元素1,3,5。
#***** Begin *****#
A = sym.FiniteSet(1,2,3,4)
B = sym.FiniteSet(3,4,5,6)
C = sym.FiniteSet(1,3,5)

#***** End *****#

# 设置全集E，E包含元素1-6
#***** Begin *****#
E = sym.FiniteSet(1,2,3,4,5,6)
E.is_UniversalSet

#***** End *****#

# 验证第一个幂等律，输出验证结果。
#***** Begin *****#
D = sym.Union(A,A)
print(D == A)

#***** End *****#

# 验证第一个分配律，输出验证结果。
#***** Begin *****#
D = sym.Intersection(A,sym.Union(B,C))
F = sym.Union(sym.Intersection(A,B),sym.Intersection(A,C))
print(D == F)

#***** End *****#

# 验证第一个吸收律，输出验证结果。
#***** Begin *****#
D = sym.Intersection(A,sym.Union(A,B))
print(D == A)

#***** End *****#

# 验证德摩根律，输出验证结果。
#***** Begin *****#
C = sym.Intersection(A,B)
D = C.complement(E)
F = sym.Union(A.complement(E),B.complement(E))
print(D == F)

# C = sym.Union(A,B)
# D = C.complement(E)
# F = sym.Intersection(A.complement(E),B.complement(E))
# print(D == F)

#***** End *****#

# 证明对任何集合X和Y,(X-Y)交(Y-X)=空集，输出验证结果(空集用 sym.EmptySet() 表示)。
#***** Begin *****#
D = sym.Intersection(A-B,B-A)
print(D == sym.EmptySet)

#***** End *****#