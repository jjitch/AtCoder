n=int(input())
flag=False
for i in range(1, 39):
    for j in range(1, 30):
        if 3**i+5**j==n:
            print(i, j)
            flag=True

if not flag:
    print(-1)