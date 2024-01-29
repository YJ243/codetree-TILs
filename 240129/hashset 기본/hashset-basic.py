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
        
''' 해설 '''
# 변수 선언 및 입력:
n = int(input())
s = set()

for _ in range(n):
    command, x = tuple(input().split())
    x = int(x)

    if command == "add":
        s.add(x)
    elif command == "remove":
        s.remove(x)
    else:
        if x in s:
            print("true")
        else:
            print("false")