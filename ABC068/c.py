n, m = map(int, input().split())
possible = False
tree = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    tree[a].append(b)

for one in tree[0]:
    for i in tree[one]:
        if i == n - 1:
            possible = True

if possible:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
