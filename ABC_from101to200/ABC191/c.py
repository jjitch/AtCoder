h, w = map(int, input().split())
graffic = []
for _ in range(h):
    graffic.append(input())

start = 0
end = 0
vertex = []

former = False
later = False


for i in range(h):
    start = 0
    end = 0
    former = False
    later = False
    for j in range(w):
        if graffic[i][j] == '#' and not former:
            start = j
            former = True
        if graffic[i][j] == "." and former and not later:
            end = j - 1
            later =True
    if start != 0 and end != 0:
        vertex.append([start, end])

# print(vertex)

height = len(vertex)
if height == 1 and vertex[0][0] == vertex[0][1]:
    print(1)
    exit()

# print(height)
l_dif = set()
r_dif = set()
for i in range(1, height):
    l = vertex[i][0]-vertex[i-1][0]
    r = vertex[i][1] - vertex[i - 1][1]
    l_dif.add(l)
    r_dif.add(r)

# print(l_dif, r_dif)
# print(len(l_dif), len(r_dif))
n = len(l_dif) + len(r_dif)
if vertex[0][0] != vertex[0][1]:
    n += 1
if vertex[-1][0] != vertex[-1][1]:
    n += 1

print(n)
    
