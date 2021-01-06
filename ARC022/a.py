S = input()

i_found = False
c_found = False
t_found = False

for s in S:
    if s == "i" or s == "I":
        i_found = True
    if i_found:
        if s == "c" or s == "C":
            c_found = True
    if i_found and c_found:
        if s == "t" or s == "T":
            t_found = True

if i_found and c_found and t_found:
    print("YES")
else:
    print("NO")
