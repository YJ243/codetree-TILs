arr = list(map(int, input().split()))
arr.sort()

ans = 0
if arr[0] + 1 == arr[1] and arr[1] + 1 == arr[2]:
    ans = 0
else:
    max_dist = max(arr[1]-arr[0], arr[2]-arr[1])
    ans = max_dist-1

print(ans)