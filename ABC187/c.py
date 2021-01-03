n = int(input())
a = set()
b=set()
for _ in range(n):
    word = input()
    if word[0]=="!":
        b.add(word.lstrip("!"))
    else:
        a.add(word)

a_num = len(a)
b_num = len(b)
c=a|b
c_num = len(c)
if a_num + b_num == c_num:
    print("satisfiable")
else:
    d = a & b
    print(d.pop())
