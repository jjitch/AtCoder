a, b = input().split()

a_sum = 0
for s in a:
    a_sum += int(s)


b_sum = 0
for s in b:
    b_sum += int(s)

ans = a_sum if a_sum > b_sum else b_sum
print(ans)