n = int(input())

arr = list(map(int, input().split()))
tmp = []
for i in range(n):
    tmp.append(arr[i])

    if i % 2 == 0:
        tmp.sort()
        print(tmp[len(tmp)//2], end=' ')