from collections import deque


class One:
    def __init__(self):
        self.string = deque()
        self.is_front = True

    def rev(self):
        if self.is_front:
            self.is_front = False
        else:
            self.is_front = True


class Another:
    def __init__(self):
        self.string = deque()
        self.is_front = False


a = input()
q = int(input())
one = One()
another = Another()
rev_num = 0

for i in range(q):
    query = list(input().split())
    if query[0] == "1":
        one.rev()
        rev_num += 1
    else:
        if query[1] == "1":
            if one.is_front:
                one.string.append(query[2])
            else:
                another.string.append(query[2])
        else:
            if not one.is_front:
                one.string.append(query[2])
            else:
                another.string.append(query[2])

if rev_num % 2 == 1:
    a = "".join(list(reversed(a)))

ans = ""
if one.is_front:
    one.string.reverse()
    ans = "".join(one.string) + a + "".join(another.string)
else:
    another.string.reverse()
    ans = "".join(another.string) + a + "".join(one.string)

print(ans)
