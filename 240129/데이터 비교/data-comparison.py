n = int(input())
arr1 = list(map(int, input().split()))
set1 = set(arr1)

n = int(input())
arr2 = list(map(int, input().split()))

for elem2 in arr2:
    if elem2 not in set1:
        print(0, end=' ')
    else:
        print(1, end=' ')