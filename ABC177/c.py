n = int(input())
a_s = list(map(int, input().split()))

sum_a = 0
mul_a = 0
mod = 1000000007

for a in a_s:
    sum_a += a
    mul_a += a*a
    sum_a %= mod
    mul_a %= mod

ans = sum_a * sum_a
ans %= mod
ans -= mul_a
ans %= mod

n = mod-2
inv = 1
base = 2

while n:
    if n & 1:
        inv = inv*base % mod
    base = base*base % mod
    n >>= 1

ans *= inv
ans %= mod

print(ans)
