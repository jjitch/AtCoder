import math

n = int(input())
a_s = list(map(int, input().split()))
gcd = a_s[0]

for a in a_s:
    gcd = math.gcd(a, gcd)

print(gcd)
