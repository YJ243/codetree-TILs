n = int(input())
d = dict()

for _ in range(n):
    command = input().split()
    if command[0] == "add":
        d[command[1]] = command[2]
    elif command[0] == "remove":
        d.pop(command[1])
    else:
        if command[1] in d:
            print(d[command[1]])
        else:
            print("None")