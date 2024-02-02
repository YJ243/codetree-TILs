n = int(input())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

arr1.sort()
arr2.sort()
for i in range(n):
    if arr1[i] != arr2[i]:
        print("No")
        exit(0)
print("Yes")