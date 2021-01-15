import collections

x, y, z, k = map(int, input().split())
a_s = list(map(int, input().split()))
b_s = list(map(int, input().split()))
c_s = list(map(int, input().split()))
a_s.sort()
b_s.sort()
c_s.sort()

xi = yi = zi = 0
rank=collections.deque([0,0,0])

for _ in range(k):
    crnt += a_s[xi] + b_s[yi] + c_s[zi]
    if crnt>rank[2]:
        pass
