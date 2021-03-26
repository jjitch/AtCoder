
n = int(input())
a_s = list(map(int, input().split()))

flag = 0
ans = 1
tmp = 0

for i in range(n):
    if i == 0:
        continue
    elif a_s[i] > a_s[i-1]:
        if flag == -1:
            ans += 1
            flag = 0
        else:
            flag = 1
    elif a_s[i] < a_s[i-1]:
        if flag == 1:
            ans += 1
            flag = 0
        else:
            flag = -1

print(ans)
