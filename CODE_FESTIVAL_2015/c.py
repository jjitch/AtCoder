from collections import deque

n, m = map(int, input().split())
a_s = list(map(int, input().split()))
b_s = list(map(int, input().split()))
a_s.sort(reverse=True)
b_s.sort(reverse=True)
a_deq = deque(a_s)
able = True

for b in b_s:
    try:
        inn = a_deq.popleft()
        if inn >= b:
            continue
        else:
            able = False
    except IndexError:
        able = False
        break

if able:
    print("YES")
else:
    print("NO")
