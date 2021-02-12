import sys

def dfs(n, now, frm):
    if n != 0:
        tree[n].remove(frm)
    now += count[n]
    ans[n] = now
    for v in tree[n]:
        dfs(v, now, n)

sys.setrecursionlimit(10000000)
n, q = map(int, input().split())
tree = [set() for _ in range(n)]
count = [0 for _ in range(n)]
ans = [0 for _ in range(n)]
for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    tree[a].add(b)
    tree[b].add(a)
for _ in range(q):
    p, x = map(int, input().split())
    p -= 1
    count[p] += x
dfs(0, 0, 0)
print(*ans)
