n = int(input())

arr = [int(input()) for _ in range(n)]

# 연속하여 동일한 숫자가 나오는 횟수를 구해보며,
# 그 중 최댓값을 갱신
ans, cnt = 0,0
for i in range(len(arr)):
    if i >= 1 and arr[i-1] < arr[i]:
        cnt += 1
    else:
        cnt = 1
    ans = max(ans, cnt)
print(ans)