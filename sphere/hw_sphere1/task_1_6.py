i = 0
contents = []
q = [0] * 4
while True:
    try:
        line = input()
    except EOFError:
        break
    contents.append(line + '\n')
s = ''.join(contents)
while i < len(s):
    if (i + 1) <= len(s) and s[i] == '(' and s[i + 1] == '*':
        while (i + 1) <= len(s) and (s[i] != '*' or s[i + 1] != ')'):
            i += 1
        if (i + 1) <= len(s):
            q[0] += 1
    elif i <= len(s) and s[i] == '{':
        while i < len(s) and s[i] != '}':
            i += 1
        if i < len(s):
            q[1] += 1
    elif (i + 1) <= len(s) and s[i] == '/' and s[i + 1] == '/':
        while (i + 1) <= len(s) and s[i] != '\n':
            i += 1
        q[2] += 1
    elif i <= len(s) and s[i] == '\'':
        i += 1
        while i <= len(s) and s[i] != '\'':
            i += 1
        if i <= len(s):
            q[3] += 1
    i += 1
for i in q:
    print(i)

