n = int(input())    # n개의 각 위치별 블럭 개수

arr = [int(input()) for _ in range(n)]
target = sum(arr) // n

ans = 0

def getMax():
    curMax, curIdx = 0,0
    for i in range(n):
        if curMax < arr[i]:
            curMax = arr[i]
            curIdx = i
    return curIdx, curMax

def getMin():
    curMin, curIdx = 10001, 0
    for i in range(n):
        if curMin > arr[i] and arr[i] != target:
            curMin = arr[i]
            curIdx = i
    return curIdx, curMin

# 제일 큰 숫자와 그 인덱스, 제일 작은 숫자와 그 인덱스 가져오기
while True:
    maxIdx, maxNum = getMax()
    minIdx, minNum = getMin()

    if maxNum == target:
        break
    
    moved_len = min(maxNum-target, target-minNum)
    arr[maxIdx] -= moved_len
    arr[minIdx] += moved_len
    ans += moved_len

print(ans)