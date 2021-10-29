from math import factorial

n = int(input())
k = int(input())
k -= 1
was = [0]*21
per = [0]*21
for i in range(1, n + 1):
    fac = factorial(n - i)
    a = k // fac
    k %= fac
    cur = 0
    for j in range(1, n + 1):
        if was[j] == 0:
            cur += 1
            if cur == (a + 1):
                per[i] = j
                was[j] = 1
for i in range(1, n + 1):
    print(per[i], end=' ')
