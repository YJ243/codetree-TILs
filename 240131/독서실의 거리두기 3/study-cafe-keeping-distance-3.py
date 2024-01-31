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

ans = 1000
# 3. 처음부터 순회하면서 가장 가까운 거리 찾아서 출력하기
x, y = 0,0

for i in range(1, len(seats)):
    if seats[i] == '1':
        y = i
        ans = min(ans, y-x)
        x, y = i,i

if ans == 1:
    ans = 0
print(ans)