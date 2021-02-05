
while True:
    mod = int(input("mod:"))
    x = int(input("init:"))
    for i in range(15):
        x *= x
        x %= mod
        print(x)
