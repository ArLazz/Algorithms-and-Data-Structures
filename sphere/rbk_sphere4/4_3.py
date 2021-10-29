def lse(x, y):
    f = [[0] * (len(y) + 1) for i in range(len(x) + 1)]
    for i in range(1, len(x) + 1):
        for j in range(1, len(y) + 1):
            if x[i - 1] == y[j - 1]:
                f[i][j] = 1 + f[i - 1][j - 1]
            else:
                f[i][j] = max(f[i - 1][j], f[i][j - 1])
    return f[-1][-1]


x = input()
y = input()
print(lse(x, y))
