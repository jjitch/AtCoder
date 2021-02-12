from collections import Counter

n = int(input())
a_s = list(map(int, input().split()))
c = Counter(a_s)
ans=0
for v in c:
    if v > c[v]:
        ans += c[v]
    if v < c[v]:
        ans += (c[v] - v)

print(ans)
