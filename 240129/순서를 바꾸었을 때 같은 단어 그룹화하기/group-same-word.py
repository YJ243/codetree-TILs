n = int(input())

arr = [input() for _ in range(n)]

ans = 0
count = dict()
for i in range(n):
    sorted_elem = ''.join(sorted(arr[i]))
    arr[i] = sorted_elem
    
    if arr[i] not in count:
        count[arr[i]] = 1
    else:
        count[arr[i]] += 1
    ans = max(ans, count[arr[i]])

print(ans)