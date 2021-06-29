import sys
sys.setrecursionlimit(3000)

n, m = map(int, input().split())
a_s = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a_s[a-1].append(b-1)

def dfs(cnt_dfs, now):
    visited[now] = 1
    s = 0
    for next in a_s[now]:
        if visited[next]:
            continue
        s += dfs(cnt_dfs, next) + 1
    return cnt_dfs+s


cnt = 0
for i in range(n):
    visited = [0 for _ in range(n)]
    cnt += 1
    cnt += dfs(0, i)

print(cnt)
