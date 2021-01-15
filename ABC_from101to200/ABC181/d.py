import itertools

s = input()
possible = False
for v in itertools.permutations(s, min(3, len(s))):
    val = 0
    for i, d in enumerate(v):
        val += int(d) * 10 ** (2-i)
    if val % 8 == 0:
        possible = True

if possible:
    print("Yes")
else:
    print("No")
