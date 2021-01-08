dishes = [int(input()) for _ in range(5)]
ceil = []
first = 10
last = 0
for i, d in enumerate(dishes):
    if d % 10 == 0:
        ceil.append(d)
    else:
        if first > d % 10:
            first = d % 10
            last = i
        ceil.append((d // 10 + 1) * 10)

print(sum([x for i, x in enumerate(ceil) if i != last])+dishes[last])
