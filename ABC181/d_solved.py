from collections import Counter

n = input()

if len(n) <= 2:
    if int(n) % 8 == 0 or int(n[::-1]) % 8 == 0:
        print("Yes")
    else:
        print("No")
    exit()

cnt = Counter(n)

for i in range(112, 1000, 8):
    a = Counter(str(i)) - cnt
    if not a:
        print("Yes")
        exit()

print("No")
