k = int(input())
a, b = map(int, input().split())
a_10 = 0
b_10 = 0
d=0
while a:
    a_10 = a_10 + a % 10*pow(k,d)
    a = a//10
    d=d+1
d=0
while b:
    b_10 = b_10 + b % 10*pow(k,d)
    b = b//10
    d=d+1
print(a_10*b_10)
