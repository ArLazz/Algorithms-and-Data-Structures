n = int(input())
s = 0
s_max = 0
if n != 0:
    for i in input().split():
        x = int(i)
        if x == 5:
            s -= 1
        else:
            s += x // 5 - 1
        s_max = max(s, s_max)
if s_max < 0:
    s_max = 0
print(s_max)
