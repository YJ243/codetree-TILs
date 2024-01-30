n = int(input())
arr = [int(input()) for _ in range(n)]

ans = 0
cur_sign = 0    # 양수면 0, 음수면 1
cur_cnt = 1
if arr[0] > 0:
    cur_sign = 0
else:
    cur_sign = 1

for i in range(1, len(arr)):

    if arr[i] > 0:
        now = 0
    else:
        now = 1
    
    if cur_sign != now:
        cur_sign = now
        cur_cnt = 1
    else:
        cur_cnt += 1
    
    ans = max(ans, cur_cnt)
ans = max(ans, cur_cnt)
print(ans)