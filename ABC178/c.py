n = int(input())
mod=1000000007
a = pow(10, n, mod)
b = pow(9, n, mod)
c = pow(8, n, mod)
ans = a - 2 * b + c
ans %= mod
print(ans)
