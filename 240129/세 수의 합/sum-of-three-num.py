n, k = map(int, input().split())

arr = list(map(int, input().split()))
freq = dict()

ans = 0
for i in range(n):
    for j in range(i+1,n):
        twoSum = arr[i]+arr[j]
        if k-twoSum in freq:
            ans += freq[k-twoSum]
        
    if arr[i] not in freq:
        freq[arr[i]] = 1
    else:
        freq[arr[i]] += 1

print(ans)