def convert(n, m):
    ans = str(n // m)
    q = ''
    l = dict()
    i = 0
    n = n % m
    l[n] = i
    i += 1
    while True:
        if n == 0:
            return '{}.{}'.format(ans, q)
        digit = (n * 10) // m
        n = (n * 10) % m
        q += str(digit)
        if n not in l:
            l[n] = i
            i += 1
        else:
            return '{}.{}({})'.format(ans, q[:l[n]], q[l[n]:])


n1, m1 = map(int, input().split())
print(convert(n1, m1))
