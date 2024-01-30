n, t = map(int, input().split())
arr = list(map(int, input().split()))

ans, cnt = 0,0
for i in range(len(arr)):
    if i >= 1 and arr[i] > t:
        if arr[i-1] > t:
            cnt += 1
        else:
            cnt = 1
    else:
        if arr[i] > 3:
            cnt = 1
    ans = max(ans, cnt)

print(ans)
    
''' 해설 '''
'''
# 변수 선언 및 입력:
n, t = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

# 연속하여 t보다 큰 숫자가 나오는 횟수를 구해보며,
# 그 중 최댓값을 갱신합니다.
ans, cnt = 0,0
for i in range(n):
    # Case 1
    if arr[i] > t:
        cnt += 1
    # Case 2
    else:
        cnt = 0
    
    ans = max(ans, cnt)
print(ans)
'''