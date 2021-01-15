t = int(input())
ans = []
for i in range(t):
    n = int(input())
    a_s = list(map(int, input().split()))
    bit = 0
    for j in range(n):
        if j == 0:
            bit = a_s[j]
        else:
            bit = a_s[j] ^ bit

    if (bit != 0 and n % 2 == 0) or (bit == 0 and n % 2 == 1):
        ans.append("First")
    else:
        ans.append("Second")

for a in ans:
    print(a)
