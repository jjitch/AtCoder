antenas = [int(input()) for _ in range(5)]
k = int(input())
farest = antenas[4] - antenas[0]
if farest>k:
    print(":(")
else:
    print("Yay!")
