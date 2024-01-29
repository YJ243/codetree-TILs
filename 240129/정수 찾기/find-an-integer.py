# 변수 선언 및 입력:
n = int(input())
arr1 = list(map(int, input().split()))
set1 = set(arr1)    # 수열 arr1의 원소를 전부 HashSet에 넣어주기

m = int(input())
arr2 = list(map(int, input().split()))

# 수열 arr2의 각 원소가 수열 arr1에 있는지 확인
for elem2 in arr2:
    # 찾지 못했다면 0을 출력
    if elem2 in set1:
        print(1)
    # 찾았다면 1을 출력
    else:
        print(0)