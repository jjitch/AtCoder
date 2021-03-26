from collections import Counter

k = int(input())
s = input()
t = input()
left = {1: k, 2: k, 3: k, 4: k, 5: k, 6: k, 7: k, 8: k, 9: k}

s_score = 45
t_score = 45
sc = Counter(s[:4])
for ke, v in sc.items():
    ke = int(ke)
    s_score -= ke
    s_score += ke * 10 ** v

tc = Counter(t[:4])
for ke, v in tc.items():
    ke = int(ke)
    t_score -= ke
    t_score += ke*10**v

for i in range(4):
    si = int(s[i])
    ti = int(t[i])
    left[si] -= 1
    left[ti] -= 1
case = 0
for s_draw in range(1, 10):
    s_tmp = s_score
    left_tmp = left.copy()
    if left_tmp[s_draw]:
        s_num = sc[str(s_draw)]
        s_tmp -= s_draw*10**s_num
        s_tmp += s_draw * 10 ** (s_num + 1)
        tmp = left_tmp[s_draw]
        left_tmp[s_draw] -= 1
        for t_draw in range(1, 10):
            t_tmp = t_score
            if left_tmp[t_draw]:
                t_num = tc[str(t_draw)]
                t_tmp -= t_draw*10**t_num
                t_tmp += t_draw * 10 ** (t_num + 1)
                if s_tmp > t_tmp:
                    case += tmp * left_tmp[t_draw]

al = (9 * k - 8) * (9 * k - 9)
print(case/al)
