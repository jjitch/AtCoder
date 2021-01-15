import itertools

n = int(input())
crd = []
for _ in range(n):
    crd.append(list(map(int, input().split())))


ans = 0
for p in itertools.combinations(crd, 2):
    a = p[0]
    b = p[1]
    lean = (b[1] - a[1]) / (b[0] - a[0])
    if - 1 <= lean <= 1:
        ans += 1

print(ans)
