s = input()

num_a = num_b = num_c = 0

for st in s:
    if st == "a":
        num_a += 1
    elif st == "b":
        num_b += 1
    elif st == "c":
        num_c += 1

if max(num_a, num_b, num_c) - min(num_a, num_b, num_c) <= 1:
    print("YES")
else:
    print("NO")
