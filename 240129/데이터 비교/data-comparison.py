# 변수 선언 및 입력:
n = int(input())
arr1 = list(map(int, input().split()))
set1 = set(arr1)    # 첫 번째 수열의 원소를 전부 HashSet에 넣어주기

n = int(input())
arr2 = list(map(int, input().split()))

# 두 번째 수열의 각 원소가 첫 번째 수열에 들어있는지 확인
for elem2 in arr2:
    # 찾지 못했다면 0을 출력
    if elem2 not in set1:
        print(0, end=' ')
    # 찾았다면 1을 출력
    else:
        print(1, end=' ')