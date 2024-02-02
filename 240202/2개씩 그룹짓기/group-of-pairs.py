n = int(input())
arr = list(map(int, input().split()))

arr.sort()

tmp = []
for i in range(n):
    num = arr[i] + arr[2*n-1-i]
    tmp.append(num)


print(max(tmp))