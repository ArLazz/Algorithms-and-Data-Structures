n = int(input())
s = 0
s1 = 0
f = False
x = int(input())
s = x
if x == 1:
    for i in range(n - 1):
        x = int(input())
        if x > (s + 1):
            s1 = s + 1
            f = True
        s += x
    if not f:
        s1 = s + 1
    print(s1)
else:
    for i in range(n - 1):
        x = int(input())
    print(1)
