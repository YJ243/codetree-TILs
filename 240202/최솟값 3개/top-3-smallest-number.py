import heapq
n = int(input())
arr = list(map(int, input().split()))

pq = []

for i in range(n):
    heapq.heappush(pq, arr[i])
    if len(pq) < 3:
        print(-1)
    else:
        tmp = []
        for j in range(3):
            tmp.append(heapq.heappop(pq))
        curr = 1
        for j in range(3):
            curr *= tmp[j]
        print(curr)
        for j in range(3):
            heapq.heappush(pq, tmp[j])