n = int(input())
arr = list(map(int, input().split()))

sorted_idx = n-2

while sorted_idx >= 0:
    if arr[sorted_idx] < arr[sorted_idx + 1]:
        # 만약 정렬이 되어있다면
        sorted_idx -= 1
    else:
        break
print(sorted_idx+1)