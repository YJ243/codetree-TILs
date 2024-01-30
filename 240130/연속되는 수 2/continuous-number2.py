# 변수 선언 및 입력
n = int(input())
arr=[int(input()) for _ in range(n)]

ans = 0
cur = 0
# 연속하여 동일한 숫자가 나오는 횟수를 구해보면서, 그 중 최댓값 갱신
for i in range(len(arr)):
    if i == 0 or arr[i-1] != arr[i]:
        cur = 1
    else:
        cur += 1

    ans = max(ans, cur)

print(ans)