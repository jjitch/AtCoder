import heapq

n = int(input())
a_s = list(map(int, input().split()))

mid = 2**(n-1)
a = list([v, i] for i, v in enumerate(a_s) if i < mid)
b = list([v, i] for i, v in enumerate(a_s) if i >= mid)
a.sort()
b.sort()
print(min(a[-1],b[-1])[1] +1)
