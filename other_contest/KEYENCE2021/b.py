from collections import Counter

n, k = map(int, input().split())
a = list(map(int, input().split()))

print(a)
a.sort()
c=Counter(a)
print(c)
print(c[8])

