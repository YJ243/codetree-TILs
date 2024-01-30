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

''' 해설 '''
'''
# 변수 선언 및 입력
n = int(input())
arr = [
	int(input())
	for _ in range(n)
]

# 연속하여 동일한 숫자가 나오는 횟수를 구해보며,
# 그 중 최댓값을 갱신합니다.

ans, cnt = 0, 0
for i in range(n):
    # Case 1
    if i >= 1 and arr[i]*arr[i-1] > 0:
        cnt += 1
    # Case 2
    else:
        cnt = 1

    ans = max(ans, cnt)
print(ans)
'''