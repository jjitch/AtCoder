a,b,c=map(int, input().split())
for i in range(1,10000):
    if (a<=i*c<=b):
        print(i*c)
        exit()

print(-1)
