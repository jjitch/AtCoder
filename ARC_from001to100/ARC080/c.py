N = int(input())
a_s = list(map(int, input().split()))
if N // 2 <= len([a for a in a_s if a % 4 == 0]):
    print("Yes")
else:
    print("No")