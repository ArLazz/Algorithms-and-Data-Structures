n = int(input())
d = {}
for i in range(n):
    words = input().split()
    if words[0] == "ADD":
        if d.get(words[1]) is None:
            d[words[1]] = words[2]
        else:
            print("ERROR")
    elif words[0] == "DELETE":
        if d.get(words[1]) is None:
            print("ERROR")
        else:
            d.pop(words[1])
    elif words[0] == "EDITPHONE":
        if d.get(words[1]) is None:
            print("ERROR")
        else:
            d[words[1]] = words[2]
    elif words[0] == "PRINT":
        if d.get(words[1]) is None:
            print("ERROR")
        else:
            print(words[1] + ' ' + d[words[1]])
