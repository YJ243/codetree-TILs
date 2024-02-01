n = int(input())
arr = list(map(int, input().split()))

# 맨 뒤에 있는 숫자들이
# 정렬된 상태로 가장 길게 놓여져 있는 것이 좋음
# 예를 들어 1 3 6 5 2 4 7 라는 수열이 있다면
# 2 4 7은 이미 정렬되어 있으므로
# 앞에 있는 1 3 6 5만 각 위치에 잘 옮겨주면 됨
# 따라서 4가 됨

# 즉, 뒤에서부터 보며 정렬되어 있지 않은 순간을 잡아
# 그 앞에 있는ㅇ ㅝㄴ소는 전부 옮겨주면 
sorted_idx = n-2

while sorted_idx >= 0:
    if arr[sorted_idx] < arr[sorted_idx + 1]:
        # 만약 정렬이 되어있다면
        sorted_idx -= 1
    else:
        break
print(sorted_idx+1)