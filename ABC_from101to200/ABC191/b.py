n, x = map(int, input().split())
a_s = list(map(int, input().split()))
ans=[]
for a in a_s:
    if a != x:
        ans.append(a)

print(*ans)