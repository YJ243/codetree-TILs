n, m = tuple(map(int, input().split())) # n개의 숫자, 거리 m이내
arr = list(map(int, input().split()))

ans, cur = 0,0

while cur < n:
    if arr[cur] == 1:
        ans += 1
        cur += 2*m+1
    else:
        cur += 1

print(ans)