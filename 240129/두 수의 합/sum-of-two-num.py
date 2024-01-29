n, k = map(int, input().split())
arr = list(map(int, input().split()))

freq = dict()

for num in arr:
    if num in freq:
        freq[num] += 1
    else:
        freq[num] = 1
ans = 0
for num in arr:
    if k-num in freq:
        ans += freq[k-num]


print(ans // 2)