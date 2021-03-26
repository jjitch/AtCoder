n = int(input())
a_s = []
p_s = []
x_s = []
for _ in range(n):
    a, p, x = map(int, input().split())
    a_s.append(a)
    p_s.append(p)
    x_s.append(x)

ans=1000000005
found=False
for i in range(n):
    if (x_s[i] > a_s[i]):
        ans = min(p_s[i], ans)
        found=True
if found:
    print(ans)
else:
    print(-1)
