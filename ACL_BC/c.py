class UnionFind:
    def __init__(self, n):
        self.par = [-1 for _ in range(n)]
        self.siz = [1 for _ in range(n)]

    def root(self, x):
        if self.par[x] == -1:
            return x
        else:
            self.par[x]=self.root(self.par[x])
            return self.par[x]

    def issame(self, x, y):
        return self.root(x)==self.root(y)

    def union(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x==y:
            return False
        
        if self.siz[x] < self.siz[y]:
            x, y = y, x
        
        self.par[y] = x
        self.siz[x] += self.siz[y]
        return True
    
    def size(self, x):
        return self.siz[self.root(x)]



n, m = map(int, input().split())
uf=UnionFind(n)
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    uf.union(a, b)
ans=0
for par in uf.par:
    if par == -1:
        ans += 1

print(ans-1)
