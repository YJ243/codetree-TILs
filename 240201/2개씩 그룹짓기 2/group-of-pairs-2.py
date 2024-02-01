n = int(input())
arr = list(map(int, input().split()))

arr.sort()

diff = []
for i in range(n):
    diff.append(arr[i+n]-arr[i])

diff.sort()
print(diff[0])