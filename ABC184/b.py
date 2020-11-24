n, x = map(int, input().split())
ss = input()
for s in ss:
    if s=="o":
        x += 1
    elif s=="x" and x>0:
        x -= 1

print(x)