n = int(input())
arr = list(map(int, input().split()))

ans = 0

def Finish():
    tmp = [0 for _ in range(n)]
    for i in range(n):
        tmp[i] = arr[i]
    tmp.sort()
    for i in range(n):
        if tmp[i] != arr[i]:
            return False
    return True

while True:
    if Finish():
        break
    moved = arr[0]

    next_idx = n-1
    for i in range(n-1, 0, -1):
        if arr[i] - 1 == arr[i-1]:
            next_idx = i-1
        else:
            break



    if moved < arr[next_idx]:
        for i in range(1, next_idx):
            arr[i-1] = arr[i]
        arr[next_idx-1] = moved
    else:
        for i in range(1, n):
            arr[i-1] = arr[i]
        arr[n-1] = moved    
    ans += 1

print(ans)