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
if seats[0] == 0 and seats[len(seats)-1] == 1:
    for i in range(len(seats)):
        if seats[i] == 1:
            if maxD < i:
                firstFill = i
elif seats[0] == 1 and seats[len(seats)-1] == 0:
    for i in range(len(seats)-1, -1, -1):
        if seats[i] == 1:
            if maxD < len(seats)-1-i:
                lastFill = len(seats)-1-i

def getMinDist():
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