def check_dig(n):
    if n % 10 == 7 or n//10 % 10 == 7 or n//100 % 10 == 7 or n//1000 % 10 == 7 or n//10000 % 10 == 7 or n//100000 % 10 == 7:
        return True
    else:
        return False


def check_oct(n):
    if n % 8 == 7 or n//8 % 8 == 7 or n//64 % 8 == 7 or n//512 % 8 == 7 or n//4096 % 8 == 7 or n//32768 % 8 == 7 or n//262144 % 8 == 7:
        return True
    else:
        return False


N = int(input())
s = 0
for n in range(1, N+1):
    if check_dig(n) or check_oct(n):
        s += 1

print(N-s)
