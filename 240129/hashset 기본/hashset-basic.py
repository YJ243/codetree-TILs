n = int(input())

s = set()
for _ in range(n):
    cmd = input().split()
    if cmd[0] == "add":
        s.add(int(cmd[1]))
    elif cmd[0] == "remove":
        s.remove(int(cmd[1]))
    else:       
        if int(cmd[1]) in s:
            print("true")
        else:
            print("false")