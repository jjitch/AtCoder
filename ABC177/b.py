s = input()
t = input()

cor = 0
ans = 0

for entry in range(len(s)-len(t)+1):
    for i in range(len(t)):
        if s[entry + i] == t[i]:
            cor += 1
    if ans < cor:
        ans = cor
    cor = 0

print(len(t)-ans)
