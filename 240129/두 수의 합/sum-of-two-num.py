n, k = map(int, input().split())
arr = list(map(int, input().split()))

freq = dict()

for i in range(n):
    for j in range(i+1,n):
        if arr[i]+arr[j] not in freq:
            freq[arr[i]+arr[j]] = 1
        else:
            freq[arr[i]+arr[j]] += 1

print(freq[k])