n = int(input())
h = []
dp = [[0, 0, 0] for _ in range(n)]

for i in range(n):
    a, b, c = map(int, input().split())
    h.append([a, b, c])

dp[0]=h[0]
for i in range(1, n):
    for j in range(3):
        one = other = 0
        if j == 0:
            one = 1
            other = 2
        elif j == 1:
            one = 0
            other = 2
        else:
            one = 0
            other = 1
        dp[i][j] = max(dp[i - 1][one] + h[i][j], dp[i - 1][other] + h[i][j])

print(max(dp[n-1]))
