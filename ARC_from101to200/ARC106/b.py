class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())


def main():
    n, m = map(int, input().split())
    a_s = tuple(map(int, input().split()))
    b_s = tuple(map(int, input().split()))
    uf = UnionFind(n)
    found = False
    for _ in range(m):
        x, y = map(int, input().split())
        uf.union(x-1, y-1)
    for root in uf.roots():
        a = 0
        b = 0
        for men in uf.all_group_members()[root]:
            a += a_s[men]
            b += b_s[men]
        if a != b:
            found = True
    if found:
        print("No")
    else:
        print("Yes")


if __name__ == "__main__":
    main()
