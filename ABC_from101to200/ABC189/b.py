n, x = map(int, input().split())
alc_sum = 0
x*=100
for i in range(n):
    v, p = map(int, input().split())
    alc = v * p
    alc_sum += alc
    if alc_sum > x:
        print(i + 1)
        exit()

print(-1)

