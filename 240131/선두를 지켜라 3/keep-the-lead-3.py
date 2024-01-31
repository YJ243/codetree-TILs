n, m = tuple(map(int, input().split()))

A_loc = [0]
B_loc = [0]

curA = 0
for _ in range(n):
    v, t = map(int, input().split())    # v속도로 t시간동안 움직임
    for _ in range(t):
        curA += v
        A_loc.append(curA)

curB = 0
for _ in range(m):
    v, t = map(int, input().split())    # v속도로 t시간동안 움직임
    for _ in range(t):
        curB += v
        B_loc.append(curB)

ans, cur_head = 0,0
hall_of_fame = 2    # 0: A가 선두, 1: B가 선두, 2: A,B가 모두 선두

for i in range(1, len(A_loc)):
    if A_loc[i] < B_loc[i]:
        cur_head = 1
    elif A_loc[i] > B_loc[i]:
        cur_head = 0
    else:
        cur_head = 2
    
    if hall_of_fame != cur_head:
        ans += 1
        hall_of_fame = cur_head


print(ans)