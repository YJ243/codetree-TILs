n, k = map(int, input().split())
arr = list(map(int, input().split()))

freq = dict()

ans = 0
for elem in arr:
    diff = k-elem
    if diff in freq:
        ans += freq[diff]

    if elem not in freq:
        freq[elem] = 1
    else:
        freq[elem] += 1

print(ans)