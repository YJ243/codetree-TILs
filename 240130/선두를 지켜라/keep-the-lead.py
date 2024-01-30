n, m = map(int, input().split())

A_loc = [0]
B_loc = [0]

curA = 0
for _ in range(n):
    v, t = tuple(map(int, input().split()))
    
    for _ in range(t):
        curA += v
        A_loc.append(curA)

curB = 0
for _ in range(m):
    v, t = tuple(map(int, input().split()))

    for _ in range(t):
        curB += v
        B_loc.append(curB)

start = 0 if A_loc[1] > B_loc[1] else 1     # A가 앞이면 0, B가 앞이면 1

cnt = 0
for i in range(2,len(A_loc)):
    cur = 0 if A_loc[i] > B_loc[i] else 1
    if cur != start:
        cnt += 1
        start = cur

print(cnt)

''' 해설 '''
'''
MAX_T = 1000000

# 변수 선언 및 입력
n, m = tuple(map(int, input().split()))
pos_a, pos_b = [0]*(MAX_T+1), [0]*(MAX_T+1)

# A가 매 초마다 서있는 위치를 기록
time_a = 1
for _ in range(n):
    v,t = tuple(map(int, input().split()))
    for _ in range(t):
        pos_a[time_a] = pos_a[time_a-1] + v
        time_a += 1

# B가 매 초마다 서있는 위치를 기록
time_b = 1
for _ in range(m):
    v, t = tuple(map(int, input().split()))
    for _ in range(t):
        pos_b[time_b] = pos_b[time_b - 1] + v
        time_b += 1

# A와 B 중 더 앞서 있는 경우를 확인하기
# A가 리더면 1, B가 리더면 2로 관리
leader, ans = 0,0
for i in range(1, time_a):
    if pos_a[i] > pos_b[i]:
        # 기존 리더가 B였다면 답을 갱신
        if leader == 2:
            ans += 1
        # 리더를 A로 변경
        leader = 1
    elif pos_a[i] < pos_b[i]:
        # 기존 리더가 A였다면
        # 답을 갱신
        if leader == 1:
            ans += 1
        # 리더를 B로 변경
        leader = 2

print(ans)
'''