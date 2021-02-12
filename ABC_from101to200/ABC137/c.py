from collections import Counter
import math


def combinations_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

n = int(input())
ss=[]
for _ in range(n):
    ss.append("".join(sorted(input())))
cs = Counter(ss)
ans=0
for v in cs:
    if cs[v] == 1:
        continue
    else:
        ans+=combinations_count(cs[v],2)
print(ans)
