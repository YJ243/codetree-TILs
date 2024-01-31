n = int(input())
seats = list(map(int,input()))

ans = 0
# 1. 중간의 1간의 사이 중 가장 먼 거리 잡아서 가운데 숫자 집어넣기
maxX, maxY = 0,0
maxD = 0
for i in range(len(seats)):
    if seats[i] == 1:
        for j in range(i+1, len(seats)):
            if seats[j] == 1:
                cur = j-i
                if cur > maxD:
                    maxX, maxY = i, j
                    maxD = j-i
                break
# 현재까지 maxD가 가장 먼 1간의 거리임
firstFill = 0
lastFill = 0

# 2. 맨 앞에 1을 넣을 수 있는 경우
if seats[0] == 0 and seats[len(seats)-1] == 1:
    for i in range(len(seats)):
        if seats[i] == 1:
            if maxD < i:
                firstFill = i
# 3. 맨 뒤에 1을 넣을 수 있는 경
elif seats[0] == 1 and seats[len(seats)-1] == 0:
    for i in range(len(seats)-1, -1, -1):
        if seats[i] == 1:
            if maxD < len(seats)-1-i:
                lastFill = len(seats)-1-i

def getMinDist():       # 현재 seats배열에서 가장 가까운 두 사람의 거리를 구해주는 함
    curMin = 1000
    for i in range(len(seats)):
        if seats[i] == 1:
            for j in range(i+1, len(seats)):
                if seats[j] == 1:
                    cur = j-i
                    curMin = min(curMin, cur)
                    break
    return curMin

if firstFill >= lastFill:
    seats[0] = 1
    ans = max(ans, getMinDist())
    seats[0] = 0
else:
    seats[len(seats)-1] = 1

    ans = max(ans, getMinDist())
    seats[len(seats)-1] = 0


seats[(maxX+maxY)//2] = 1
ans = max(ans, getMinDist())

print(ans)

''' 해설 '''
'''
import sys

INT_MAX = sys.maxsize

# 변수 선언 및 입력:
n = int(input())
seats = list(input())

# Step1-1. 최적의 위치 찾기
max_dist = 0
max_i, max_j = -1, -1
for i in range(n):
    if seats[i] == '1':
        for j in range(i+1, n):
            if seats[j] == '1':
                # 1간의 쌍을 골랐을 때
                # 두 좌석간의 거리가 지금까지의 최적의 값보다 더 좋다면 값을 갱신
                if j - i > max_dist:
                    max_dist = j-i

                    # 이때, 두 좌석의 위치를 기억
                    max_i, max_j = i, j
                # 인접한 쌍을 찾았으므로 빠져나옴
                break

# Step1-2. 최적의 위치 찾기(예외 처리)
# 만약 맨 앞 좌석이 비거나, 맨 뒷 좌석이 비어있는 경우 예외 처리를 해주기
max_dist2 = -1
max_idx = -1
# 맨 앞 좌석이 비어있을 때, 맨 앞 좌석에 배정하면 거리가 얼마나 줄어드는지 확인
if seats[0] == '0':
    dist = 0
    for i in range(0, n):
        if seats[i] == '1':
            break
        dist += 1
    
    if dist > max_dist2:
        max_dist2 = dist
        max_idx = 0

# 맨 뒷 좌석이 비어있을 때, 맨 뒷좌석에 배정하면
# 거리가 얼마나 줄어드는지 확인
if seats[n-1] == '0':
    dist = 0
    for i in range(n-1, -1, -1):
        if seats[i] == '1':
            break
        dist += 1
    
    if dist > max_dist2:
        max_dist2 = dist
        max_idx = n-1

# Step2. 최적의 위치에 1을 놓기
# 앞서 찾은 자리들 중 최적의 위치에 놓으면 됨
if max_dist2 >= max_dist // 2:
    seats[max_idx] = '1'
else:
    seats[(max_i+max_j) // 2] = '1'

# Step3. 이제 인접한 쌍들 중 가장 가까운 1간의 쌍을 찾기
# 이대의 값이 답이 됨
ans = INT_MAX
for i in range(n):
    if seats[i] == '1':
        for j in range(i+1, n):
            if seats[j] == '1':
                ans = min(ans, j-i)

                # 인접한 쌍을 찾았으니 빠져나오기
                break

print(ans)
'''