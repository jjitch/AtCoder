h, w = map(int, input().split())
ss = []
for _ in range(h):
    ss.append(input())

# print(*ss, sep='\n')

n = 0
for i in range(h - 1):
    for j in range(w - 1):
        cnt = 0
        if ss[i][j] == '#':
            cnt += 1
        if ss[i][j+1] == '#':
            cnt += 1
        if ss[i+1][j] == '#':
            cnt += 1
        if ss[i+1][j+1] == '#':
            cnt += 1

        if cnt == 1 or cnt == 3:
            n += 1

print(n)
