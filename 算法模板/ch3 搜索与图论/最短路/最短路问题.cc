#include <iostream>
using namespace std;
/*
单源最短路：从一个点开始到其他点的最短路
1、所有边权都是正数 m是边数，n是点数
    朴素Dijkstra算法O(N^2) 适合稠密图(边数很多) 和边数无关
    堆优化Dijkstra算法O(mlogN) 适合稀疏图(边数和点数差不多)
2、存在负权边
    Bellman-Ford O(nm) 不超过K条边的最短路问题只能用这个
    SPFA 一般：O(m) 最坏O(nm)

多源汇最短路：起点和终点不确定
    Floyd算法 O(n^3)
*/

/*
难点：将实际问题抽象为最短路问题 建图 抽象出点和边
*/
int main()
{
    
}