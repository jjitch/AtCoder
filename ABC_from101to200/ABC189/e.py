import numpy as np


def op1():
    return np.array([[0, 1, 0], [-1, 0, 0], [0, 0, 1]], dtype=np.int64)


def op2():
    return np.array([[0, -1, 0], [1, 0, 0], [0, 0, 1]], dtype=np.int64)


def op3(p):
    return np.array([[-1, 0, 2 * p], [0, 1, 0], [0, 0, 1]], dtype=np.int64)


def op4(p):
    return np.array([[1, 0, 0], [0, -1, 2*p], [0, 0, 1]], dtype=np.int64)


def operation(o, p=0):
    if o == 1:
        return op1()
    elif o == 2:
        return op2()
    elif o == 3:
        return op3(p)
    else:
        return op4(p)


n = int(input())
orign = []
for i in range(n):
    x, y = map(int, input().split())
    orign.append(np.array([x, y, 1]))
m = int(input())
cum_op = [np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]], dtype=np.int64)]
for i in range(m):
    der = list(map(int, input().split()))
    ori = cum_op[-1]
    if der[0] == 1 or der[0] == 2:
        cum_op.append(operation(der[0])@ori)
    else:
        cum_op.append(operation(der[0],der[1])@ori)
q = int(input())
ans=[]
for i in range(q):
    a, b = map(int, input().split())
    mul = np.dot(cum_op[a], orign[b - 1])
    ans.append((mul[0], mul[1]))

for v in ans:
    print(v[0], v[1])
