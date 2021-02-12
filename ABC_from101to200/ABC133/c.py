l, r = map(int, input().split())
m=2019
ans=2020

for i in range(l, r):
    for j in range(i+1, r + 1):
        t = (i * j % m)
        ans = min(ans, t)
        if ans == 0:
            print(0)
            exit()

print(ans)