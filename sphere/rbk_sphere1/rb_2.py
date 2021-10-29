n = int(input())

m = [[0, 0]] * n
c = 0

for i in range(n):
    m[i] = list(reversed(list(map(int, input().split()))))
m = (sorted(m))
c = m[0][1]
n = 1

while c <= m[len(m) - 1][0] and (len(m) > 1):
    j = 1
    while m[j][0] < c:
        j += 1
    c += m[j][1]
    del m[j]
    n += 1

print(n)
