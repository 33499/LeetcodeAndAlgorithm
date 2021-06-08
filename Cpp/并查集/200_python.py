from typing import List
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # 并查集：使用横坐标*列数+纵坐标作为元素在并查集中的唯一标识
        # 岛屿数量 = （总元素个数 - 水的个数）中的连通块的个数
        class UnionFind:
            def __init__(self, n):
                # 总数
                self.size = n
                self.p = [i for i in range(n)]

            def find(self, x):
                # 查找根节点，即当前元素所属的集合
                if self.p[x] != x:
                    self.p[x] = self.find(self.p[x])
                return self.p[x]

            def union(self, a, b):
                
                ar, br = self.find(a), self.find(b)
                # 两个元素位于同一个集合，跳过
                if ar == br:
                    return
                # 不在同一个集合，合并
                else:
                    self.p[ar] = br 
                    self.size -= 1

        n, m = len(grid), len(grid[0])
        ocean = 0   # 统计水的个数

        uf = UnionFind(n*m)

        for i in range(n):
            for j in range(m):
                # 统计水的个数
                if grid[i][j] == "0":
                    ocean += 1
                else:
                    # 只需向右和向下查看
                    if i+1 < n and grid[i+1][j]=="1":
                        uf.union(i*m+j, (i+1)*m+j)
                    if j+1 < m and grid[i][j+1]=="1":
                        uf.union(i*m+j, i*m+(j+1))
                
        return uf.size - ocean
