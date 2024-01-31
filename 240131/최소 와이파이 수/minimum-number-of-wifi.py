n, m = tuple(map(int, input().split())) # n개의 숫자, 거리 m이내
arr = list(map(int, input().split()))


# 사람이 살고 있는 곳이 나오면
# 와이파이를 해당 위치로부터 오른족으로 m만큼 떨어진 곳에 놓은 뒤,
# 2m만큼 떨어진 곳에서 시작하여 다시 탐색을 진행
ans, cur = 0,0

while cur < n:
    if arr[cur] == 1:
        ans += 1
        cur += 2*m+1
    else:
        cur += 1

print(ans)