n = int(input())
a = tuple(map(int, input().split()))
b = tuple(map(int, input().split()))
c = []
a_max = 0

for i in range(n):
    a_max = a[i] if a[i] > a_max else a_max
    if i == 0:
        c.append(a[i] * b[i])
        continue
    c.append(max(c[i - 1], a_max * b[i]))

for v in c:
    print(v)
