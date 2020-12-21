H, W = map(int, input().split())
a_s=[]
for h in range(H):
    a_s.extend(list(map(int, input().split())))
m = min(a_s)
s = 0
for a in a_s:
    s += a - m
print(s)
