n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

pro=0

for i in range(n):
    pro += (a[i] * b[i])

if pro == 0:
    print("Yes")
else:
    print("No")
    