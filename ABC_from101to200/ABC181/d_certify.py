from collections import Counter


def ok():
    print("Yes")
    exit()


string = input()


if len(string) == 1:
    if string == '8':
        ok()

if len(string) == 2:
    if int(string) % 8 == 0:
        ok()
    else:
        string = string[-1] + string[0]
        if int(string) % 8 == 0:
            ok()

s = Counter(string)
for v in range(104, 1000, 8):
    c = Counter(str(v))
    if not c - s:
        ok()

print("No")
