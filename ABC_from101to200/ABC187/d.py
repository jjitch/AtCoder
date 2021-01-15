n = int(input())
sum_a = 0
diff=[]
for _ in range(n):
    a, b = map(int, input().split())
    diff.append(2 * a + b)
    sum_a += a

list.sort(diff, reverse=True)
ans = 0
for d in diff:
    sum_a -= d
    ans += 1
    if sum_a < 0:
        break

print(ans)
