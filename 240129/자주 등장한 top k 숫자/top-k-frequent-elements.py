n, k = map(int, input().split())
arr = list(map(int, input().split()))

freq = dict()
for num in arr:
    if num not in freq:
        freq[num] = 1
    else:
        freq[num] += 1

sorted_freq = sorted(freq.items(), key=lambda x: (-x[1], -x[0]))


for i in range(k):
    print(sorted_freq[i][0], end=' ')