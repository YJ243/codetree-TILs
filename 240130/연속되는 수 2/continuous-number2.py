n = int(input())
arr=[int(input()) for _ in range(n)]


ans = 0
cur = 0
for i in range(len(arr)):
    if i == 0 or arr[i-1] != arr[i]:
        cur = 1
    else:
        cur += 1

    ans = max(ans, cur)

print(ans)