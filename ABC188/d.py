n, C = map(int, input().split())
events=[]
for i in range(n):
    a, b, c = map(int, input().split())
    events.append((a-1, c))
    events.append((b, -c))

events.sort()
ans = 0
fee = 0
t = 0
for x, f in events:
    if t != x:
        ans += min(C, fee) * (x - t)
        t = x
    fee += f

print(ans)
