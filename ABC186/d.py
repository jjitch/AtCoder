n = int(input())
a_s = list(map(int, input().split()))
a_s.sort()
s = 0
num = len(a_s)
for i, a in enumerate(a_s):
    s += a * (i * 2 - num + 1)

print(s)
