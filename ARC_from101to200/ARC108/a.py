import math

s, p = map(int, input().split())
found = False
for i in range(int(math.sqrt(p))):
    if p % (i + 1) == 0:
        if p // (i + 1) + i + 1 == s:
            found = True
            break

if found:
    print("Yes")
else:
    print("No")
