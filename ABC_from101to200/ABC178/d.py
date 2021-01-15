s = int(input())
if s in [1, 2]:
    print(0)
    exit()
dp=[0 for _ in range(2005)]
dp[0] = 1
for n in range(3,s+1):
    dp[n] = dp[n - 1] + dp[n - 3]

print(dp[s]%1000000007)
