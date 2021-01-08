import math

n = int(input())
ways = [int(input()) for _ in range(5)]
m = min(ways)
print(math.ceil(n / m) + 4)
