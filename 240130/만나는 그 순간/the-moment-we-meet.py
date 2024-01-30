n, m = map(int, input().split())

A_loc = [0]
B_loc = [0]
curA, curB = 0,0

for _ in range(n):
    d, t = input().split()
    t = int(t)
    while t > 0:
        if d == 'L':
            curA -= 1
            A_loc.append(curA)
        else:
            curA += 1
            A_loc.append(curA)
        t -= 1

for _ in range(m):
    d, t = input().split()
    t = int(t)
    while t > 0:
        if d == 'L':
            curB -= 1
            B_loc.append(curB)
        else:
            curB += 1
            B_loc.append(curB)
        t -= 1

ans = -1

for i in range(1, min(len(A_loc), len(B_loc))):
    if A_loc[i] == B_loc[i]:
        ans = i
        break
    

print(ans)