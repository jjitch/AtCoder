from math import ceil

n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
a.append(n+1)
dif = []
cur = 0
for v in a:
    x = v - cur - 1
    if x:
        dif.append(x)
    cur = v

ans = 0
if not dif:
    print(0)
    exit()
k = min(dif)
for d in dif:
    ans += ceil(d / k)

print(ans)
