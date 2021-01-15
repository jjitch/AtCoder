def dfs(v, x):
    seen[v] += 1
    for node in nodes[v]:
        if seen[node] == 1:
            continue
        nodes_counter[node]+=x
        dfs(node, x)


n = int(input())
edges = []
nodes = [[] for _ in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edges.append([a, b])
    nodes[a].append(b)
    nodes[b].append(a)


nodes_counter = [0 for _ in range(n)]
q = int(input())
for _ in range(q):
    t, e, x = map(int, input().split())
    seen = [0 for _ in range(n)]
    if t == 1:
        seen[edges[e]] += 1
    else:
        seen[edges[e]] += 1
    dfs(edges[t-1], x)

print(n, edges, nodes, nodes_counter)
