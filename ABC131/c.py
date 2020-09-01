import math

def cnt(a: int, k: int):
    return a // k


a, b, c, d = map(int, input().split())
m_b_c = cnt(b, c)
m_b_d = cnt(b, d)
m_b_cd = cnt(b, c * d // math.gcd(c, d))
