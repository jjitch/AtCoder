n = input()
r = ''.join(list(reversed(n)))
r = int(r)
r = str(r)

judge = True
for i in range(len(r)):
    if n[i]!=r[i]:
        judge=False

if judge:
    print("Yes")
else:
    print("No")
    
