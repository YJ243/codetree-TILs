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

''' 해설 '''
'''
MAX_T = 1000000

# 변수 선언 및 입력
n, m = tuple(map(int, input().split()))
pos_a, pos_b = [0] * (MAX_T + 1), [0] * (MAX_T + 1)

# A가 매 초마다 서있는 위치를 기록
time_a = 1
for _ in range(n):
    v, t = tuple(map(int, input().split()))
    for _ in range(t):
        pos_a[time_a] = pos_a[time_a-1]+v
        time_a += 1

# B가 매 초마다 서있는 위치를 기록
time_b = 1
for _ in range(m):
    v, t = tuple(map(int, input().split()))
    for _ in range(t):
        pos_b[time_b] = pos_b[time_b - 1] + v
        time_b += 1

# A와 B 중 더 앞서 있는 경우를 확인하기
# A가 리더면 1, B가 리더면 2, 둘다 리더면 3으로 관리하기
leader, ans = 0, 0
for i in range(1, time_a):
    if pos_a[i] > pos_b[i]:
        # 조합이 바뀌었다면 답을 갱신
        if leader != 1:
            ans += 1
        # 리더를 A로 변경
        leader = 1
    
    elif pos_a[i] < pos_b[i]:
        # 조합이 바뀌었다면 답을 갱신
        if leader != 2:
            ans += 1
        # 리더를 B로 변경
        leader = 2
    else:
        # 조합이 바뀌었다면 답을 갱신
        if leader != 3:
            ans += 1
        # 리더를 둘 다로 변경
        leader = 3
print(ans)
'''