n = int(input())
a_s = list(map(int, input().split()))
b = 0
c = 0
b_max = 0
ans = 0
for a in a_s:
    b += a
    ans = max(ans, c + b_max)
    c += b

print(ans)
