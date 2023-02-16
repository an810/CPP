'''
knapsack
c1x1+ c2x2 + ... + cnxn -> max
f(x) = a1x1 + a2x2 + ... + anxn <= b
4 8
10 5 3 6 
5 3 2 4
'''

import sys
def input():
    [n] = [int(x) for x in sys.stdin.readline().split()]
    c = [int(x) for x in sys.stdin.readline().split()]
    a = [int(x) for x in sys.stdin.readline().split()]
    return n,c,a

def solution():
    if f > fmax: # the objective value of the current solution is better than the best solution found so far
        fmax = f
        print('update best ', fmax,'solution is ', x[1:])

def Try(k):
    global rb, f
    for v in range(rb//a[k], -1, -1):
        x[k] = v
        W = W + a[k]*x[k]
        f = f + c[k]*x[k]
        if k == n:
            solution()
        else:
            # branch and bound evaluation to be added here
            g = f + rb/a[k+1] # g is the upper bound of the objective function f(x)
            if g > fmax:
                Try(k+1)
        f = f - c[k]*x[k]
        W = W - a[k]*x[k]
        rb = rb + a[k]*x[k]

n,c,a = input()
c.insert(0,-1)
a.insert(0,-1)
for i in range(1, n+1):
    for j in range(i+1, n+1):
        if c[i]/a[i] < c[j]/a[j]:
            tmp = c[i]
            c[i] = c[j]
            c[j] = tmp
            tmp = a[i]
            a[i] = a[j]
            a[j] = tmp
x = [0 for i in range (n+1)]
W = 0 # accumulated weight of items selected
rb = b # remaining capacity of the bin (rb = b-W)
f = 0
fmax = 0
Try(1)
# print(c,a)




