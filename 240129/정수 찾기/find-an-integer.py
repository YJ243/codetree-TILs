n = int(input())
arr1 = list(map(int, input().split()))
set1 = set(arr1)

m = int(input())
arr2 = list(map(int, input().split()))
for elem2 in arr2:
    if elem2 in set1:
        print(1)
    else:
        print(0)