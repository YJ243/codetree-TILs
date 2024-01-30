# 변수 선언 및 입력
n, m = map(int, input().split())

A_loc = [0]
B_loc = [0]
curA, curB = 0,0

# A가 매 초마다 서있는 위치를 기록
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

# B가 매 초마다 서있는 위치를 기록
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

# 최초로 만나는 시간을 구합니다.
ans = -1
for i in range(1, min(len(A_loc), len(B_loc))):
    if A_loc[i] == B_loc[i]:
        ans = i
        break
    

print(ans)

''' 해설 ''' 
'''
MAX_T = 1000000

# 변수 선언 및 입력
n, m = tuple(map(int, input().split()))
pos_a, pos_b = [0]*(MAX_T+1), [0]*(MAX_T+1)

# A가 매 초마다 서있는 위치를 기록
time_a = 1
for _ in range(n):
    d, t = tuple(input().split())
    for _ in range(int(t)):
        pos_a[time_a] = pos_a[time_a-1] + (1 if d == 'R' else -1)
        time_a += 1

# B가 매 초마다 서있는 위치를 기록
time_b = 1
for _ in range(m):
    d, t = tuple(input().split())
    for _ in range(int(t)):
        pos_b[time_b] = pos_b[time_b-1] + (1 if d == 'R' else -1)
        time_b += 1

# 최초로 만나는 시간을 구하기
ans = -1
for i in range(1, time_a):
    if pos_a[i] == pos_b[i]:
        ans = i
        break

print(ans)
'''