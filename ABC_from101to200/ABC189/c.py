n = int(input())
a = tuple(map(int, input().split()))
cum = [0]
for i in range(n):
    cum.append(cum[i] + a[i])

ans = 0

for l in range(n):
    for r in range(l, n):
        b = cum[r + 1] - cum[l]
        ans = ans if ans > b else b

print(ans)
