n, m = map(int, input().split())

A_loc = [0]
B_loc = [0]

curA = 0
for _ in range(n):
    v, t = tuple(map(int, input().split()))
    
    while t > 0:
        curA += v
        A_loc.append(curA)
        t -= 1

curB = 0
for _ in range(m):
    v, t = tuple(map(int, input().split()))

    while t > 0:
        curB += v
        B_loc.append(curB)
        t -= 1


start = 0 if A_loc[1] > B_loc[1] else 1     # A가 앞이면 0, B가 앞이면 1

cnt = 0
for i in range(2,len(A_loc)):
    cur = 0 if A_loc[i] > B_loc[i] else 1
    if cur != start:
        cnt += 1
        start = cur

print(cnt)