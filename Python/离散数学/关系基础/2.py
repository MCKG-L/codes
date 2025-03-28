import functools

class Relation(object):
    def __init__(self, sets, rel):
        #rel为sets上的二元关系
        assert not(len(sets)==0 and len(rel) > 0) #不允许sets为空而rel不为空
        assert sets.issuperset(set([x[0] for x in rel]) | set([x[1] for x in rel])) #不允许rel中出现非sets中的元素
        self.rel = rel
        self.sets = sets

    def __str__(self):
        relstr = '{}'
        setstr = '{}'
        if len(self.rel) > 0:
            relstr = str(self.rel)
        if len(self.sets) > 0:
            setstr = str(self.sets)
        return 'Relation: ' + relstr + ' on Set: ' + setstr

    def __eq__(self, other):
        #判断两个Relation对象是否相等，关系及集合都要相等
        return self.sets == other.sets and self.rel == other.rel

    def diagonalRelation(self):
        #返回代表IA的Relation对象
        return Relation(self.sets, set([(a, a) for a in self.sets]))

    def __mul__(self, other):
        assert self.sets == other.sets
        #实现两个关系的合成，即self*other表示other合成self。请注意是先看other的序偶
        #返回合成的结果，为一个Relation对象
        return Relation(self.sets, set([(x, z) for (x, y1) in other.rel for (y2, z) in self.rel if y1 == y2]))

    def __pow__(self, power, modulo=None):
        assert power >= -1
        # 实现同一关系的多次合成，重载**运算符，即self*self*self=self**3
        # 在每个分支中返回对应的结果，结果是一个Relation对象
        if power == -1:
            return Relation(self.sets, set([(x[1], x[0]) for x in self.rel]))
        elif power == 0:
            return self.diagonalRelation()
        else:
            return self**(power-1) * self

    def __add__(self, other):
        assert self.sets == other.sets
        #实现两个关系的并运算，重载+运算符，即self+other表示self并other
        #请注意，是Relation对象rel成员的并返回结果为一个Relation对象
        return Relation(self.sets, self.rel.union(other.rel))

    def toMatrix(self):
        #将序偶集合形式的关系转换为矩阵。
        #为保证矩阵的唯一性，需对self.sets中的元素先排序
        matrix = []
        elems = sorted(list(self.sets))
        line = [0]*len(self.sets)
        for elem in elems:
            #实现转换为矩阵的功能
            tups = [x for x in self.rel if x[0] == elem]
            for item in tups:
                line[elems.index(item[1])] = 1
            matrix.append(line)
            line = [0]*len(self.sets)
        return matrix

    def isReflexive(self):
        #判断self是否为自反关系，是则返回True，否则返回False
        for a in self.sets:
            if not((a, a) in self.rel):
                return False
        return True

    def isIrreflexive(self):
        # 判断self是否为反自反关系，是则返回True，否则返回False
        for a in self.sets:
            if (a, a) in self.rel:
                return False
        return True
        
    def isSymmetric(self):
        # 判断self是否为对称关系，是则返回True，否则返回False
        for (a, b) in self.rel:
            if not ((b, a) in self.rel):
                return False
        return True

    def isAsymmetric(self):
        # 判断self是否为非对称关系，是则返回True，否则返回False
        for (a, b) in self.rel:
            if (b, a) in self.rel:
                return False
        return True
        
    def isAntiSymmetric(self):
        # 判断self是否为反对称关系，是则返回True，否则返回False
        for (a, b) in self.rel:
            if (b, a) in self.rel:
                if not (a == b):
                    return False
        return True

    def isTransitive(self):
        # 判断self是否为传递关系，是则返回True，否则返回False
        for (a, b) in self.rel:
            tempR = [(x, y) for (x, y) in self.rel if x == b]
            if len(tempR) > 0:
                for (b, c) in tempR:
                    if not ((a, c) in self.rel):
                        return False
        return True

    def reflexiveClosure(self):
        #求self的自反闭包，注意使用前面已经重载过的运算符
        #返回一个Relation对象，为self的自反闭包
        return self + self.diagonalRelation()

    def symmetricClosure(self):
        # 求self的对称闭包，注意使用前面已经重载过的运算符
        # 返回一个Relation对象，为self的对称闭包
        return self + self**-1

    def transitiveClosure(self):
        closure = self
        # 求self的传递闭包，注意使用前面已经重载过的运算符
        # 该方法实现的算法：严格按照传递闭包计算公式求传递闭包
        for power in range(2, len(self.sets) + 1):
            closure = closure + self ** power
        return closure

    def transitiveClosure3(self):
        #该方法利用Roy-Warshall计算传递闭包
        #现将关系转换为矩阵，再调用__warshall函数
        m = self.toMatrix()
        return self.__warshall(m)

    def __warshall(self, a):
        assert (len(row) == len(a) for row in a)
        n = len(a)
        #请在下面编程实现Roy-Warshall求传递闭包的算法
        #参数a：为一个关系矩阵
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    a[i][j] = a[i][j] or (a[i][k] and a[k][j])
        return a

def isEquivalenceRelation(rel):
    #该函数对给定的Relation对象rel，判断其是否为等价关系
    #是则返回True，否则返回False
    if rel.isReflexive() and rel.isSymmetric() and rel.isTransitive():
        return True
    else:
        return False

def createPartition(rel):
    #对给定的Relation对象rel，求其决定的rel.sets上的划分
    #如果rel不是等价关系，返回空集
    if not isEquivalenceRelation(rel):
        print("The given relation is not an Equivalence Relation")
        return set([])
    #如rel是等价关系，请编程实现求划分的程序
    partition = set([])
    for a in rel.sets:
        partition.add(frozenset(y for (x, y) in rel.rel if x == a))
    return partition
        
def createEquivalenceRelation(partition, A):
    #对给定的集合A，以及A上的一个划分partition
    #生成由该划分决定的等价关系
    assert functools.reduce(lambda x, y: x.union(y), partition) == A
    return Relation(A, set([(a,b) for p in partition for a in p for b in p]))

def isPartialOrder(rel):
    # 该函数对给定的Relation对象rel，判断其是否为半序关系
    #是则返回True，否则返回False。
    if rel.isReflexive() and rel.isAntiSymmetric() and rel.isTransitive():
        return True
    else:
        return False
    
def isQuasiOrder(rel):
    # 该函数对给定的Relation对象rel，判断其是否为拟序关系
    # 是则返回True，否则返回False。
    if rel.isIrreflexive() and rel.isTransitive():
        return True
    else:
        return False

def isLinearOrder(rel):
    # 该函数对给定的Relation对象rel，判断其是否为全序关系
    if not isPartialOrder(rel):
        return False
    else:
        for a in rel.sets:
            for b in rel.sets:
                if not ((a, b) in rel.rel or (b, a) in rel.rel):
                    return False
        return True

def join(rel1, rel2):
    #对给定的关系rel1和rel2
    assert rel1.sets == rel2.sets
    #首先得到二者的矩阵
    M1 = rel1.toMatrix()
    M2 = rel2.toMatrix()

    m = len(M1)
    n = m
    M = []
    #实现关系矩阵的join运算，结果存于M中
    for i in range(m):
        row = []
        for j in range(n):
            row.append(M1[i][j] or M2[i][j])
        M.append(row)
    return M

def meet(rel1, rel2):
    # 对给定的关系rel1和rel2
    assert rel1.sets == rel2.sets

    # 首先得到二者的矩阵
    M1 = rel1.toMatrix()
    M2 = rel2.toMatrix()

    m = len(M1)
    n = m
    M = []
    # 实现关系矩阵的meet运算，结果存于M中
    for i in range(m):
        row = []
        for j in range(n):
            row.append(M1[i][j] and M2[i][j])
        M.append(row)
    return M

def booleanProduct(rel1, rel2):
    # 对给定的关系rel1和rel2
    assert rel1.sets == rel2.sets

    # 首先得到二者的矩阵
    M1 = rel1.toMatrix()
    M2 = rel2.toMatrix()

    m = len(M1)
    n = m
    M = []
    #**********  Begin  **********#
    # 实现关系矩阵的布尔乘积运算，结果存于M中

    for i in range(n):
        L = []
        for j in range(m):
            x = 0
            for k in range(m):
                x = x | (M1[i][k] & M2[k][j])
            L.append(x)
        M.append(L)
    #**********  End  **********#
    return M
