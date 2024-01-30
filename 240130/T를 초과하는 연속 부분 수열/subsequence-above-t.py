n, t = map(int, input().split())
arr = list(map(int, input().split()))

ans, cnt = 0,0
for i in range(len(arr)):
    if i >= 1:
        if arr[i] > t and arr[i-1] > t:
            cnt += 1
        else:
            cnt = 1
    else:
        if arr[i] > 3:
            cnt = 1
    ans = max(ans, cnt)

print(ans)