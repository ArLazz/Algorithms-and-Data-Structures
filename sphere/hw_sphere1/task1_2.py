def nod(a, b):
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return a + b


s = 0
n = int(input())
x1 = int(input())
for i in range(n - 1):
    x2 = int(input())
    if nod(x1, x2) > 1:
        s += 1
    x1 = x2
print(s)
