def dfs(frm):
    for x in graph[frm]:
        if not x:
            return False
        

n, m = map(int, input().split())
a_s = list(map(int, input().split()))
graph=[[] for _ in range(n)]
for i in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    graph[x].append(y)

print(graph)
root=[]