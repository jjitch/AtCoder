from math import sqrt

sx, sy, ex, ey, t, v = map(int, input().split())
n = int(input())
possible=False
for i in range(n):
    x, y = map(int, input().split())
    a = sqrt((sx - x)** 2 + (sy - y)** 2)
    b = sqrt((ex - x)** 2 + (ey - y)** 2)
    if a + b <= v * t:
        possible=True

if possible:
    print("YES")
else:
    print("NO")
