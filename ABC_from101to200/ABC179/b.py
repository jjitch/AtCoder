n = int(input())
found = False
con = 0
for i in range(n):
    a, b = map(int, input().split())
    if (a == b):
        con += 1
    else:
        con = 0
    if con == 3:
        found = True

if found:
  print("Yes")
else:
  print("No")
