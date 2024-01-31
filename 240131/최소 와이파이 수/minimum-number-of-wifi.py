n, m = tuple(map(int, input().split())) # n개의 숫자, 거리 m이내
arr = list(map(int, input().split()))

ans = 0
cur = m

if m == 0:
    print(n-1)
    exit(0)
if n <= m:
    print(1)
    exit(0)
    
while True:
    CanbeSetup = False
    for i in range(cur-m, cur):
        if arr[i]:
            CanbeSetup = True

    if CanbeSetup or cur + m >= n:
        ans += 1
        cur += 2*m+1
    else:
        cur += m

    if cur >= n:
        break

print(ans)