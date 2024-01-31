n = int(input())
seats = list(input())

# 1. 1과 1사이 중 가장 먼 곳 찾기
x, y = 0, 0
maxX, maxY = 0,0
curMax = 0
for i in range(1, len(seats)):
    if seats[i] == '1':
        y = i
        if curMax < y-x:
            curMax = y-x
            maxX, maxY = x, y
        x, y = i, i

# 2. 그 가운데에다가 1을 집어넣기
seats[(maxX+maxY)//2] = '1'

ans = 1000  # 현재 가장 가까운 두 사람 거
# 3. 처음부터 순회하면서 가장 가까운 거리 찾아서 출력하기
x, y = 0,0

for i in range(1, len(seats)):
    if seats[i] == '1':
        y = i
        ans = min(ans, y-x)
        x, y = i,i

print(ans)

''' 해설 '''
'''
import sys

INT_MAX = sys.maxsize

# 변수 선언 및 입력:
n = int(input())
seats = list(input())

# Step1. 최적의 위치 찾기
# 인접한 쌍들 중 가잔 먼 1간의 쌍을 찾기
max_dist = 0
max_i, max_j = -1, -1
for i in range(n):
    if seats[i] == '1':
        for j in range(i+1, n):
            if seats[j] == '1':
                # 1간의 쌍을 골랐을 때 두 좌석간의 거리가 지금까지의 최적의 답보다 더 좋다면
                # 답을 갱신해주기
                if j-i > max_dist:
                    max_dist = j-i

                    # 이 때, 두 좌석의 위치를 기억하기
                    max_i, max_j = i,j
                
                # 인접한 쌍을 찾았으므로 빠져나오기
                break

# Step2. 최적의 위치에 1을 놓기
# 가장 먼 쌍의 위치 가운데에 놓으면 됨
seats[(max_i + max_j) // 2] = '1'

# Step 3. 이제 인접한 쌍들 중 가장 가까운 1간의 쌍을 찾기
# 이때의 값이 답이 됨
ans = INT_MAX
for i in range(n):
    if seats[i] == '1':
        for j in range(i+1, n):
            if seats[j] == '1':
                ans = min(ans, j-i)

                # 인접한 쌍을 찾았으므로 빠져나오기
                break

print(ans)
'''