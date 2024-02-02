n = int(input())
arr = list(map(int, input().split()))

arr1 = sorted(arr)
arr2 = arr1[::-1]

for i in range(n):
    print(arr1[i], end=' ')
print()
for i in range(n):
    print(arr2[i], end=' ')