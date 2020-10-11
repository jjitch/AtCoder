ck = list(map(int, input().split()))
s = sum(ck)
ans=False

for i in range(2 ** 4):
    h = 0
    for j in range(4):
        if ((i >> j) & 1):
            h += ck[j]
    if h==s//2 and s%2==0:
        ans=True
        break


if ans:
    print("Yes")
else:
    print("No")