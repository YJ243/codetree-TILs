n = int(input())
arr = input().split()

for i in range(n):
    arr[i] = ord(arr[i])-ord('A')

def IsSorted():
    tmp = [0 for _ in range(n)]
    for i in range(n):
        tmp[i] = arr[i]
    tmp.sort()

    if tmp == arr:
        return True
    else:
        return False
ans = 0
while True:
    if IsSorted():
        break
    
    for i in range(n-1):
        if arr[i] > arr[i+1]:
            ans += 1
            arr[i], arr[i+1] = arr[i+1], arr[i]

print(ans)