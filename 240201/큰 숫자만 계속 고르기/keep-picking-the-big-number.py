import heapq
n, m = map(int, input().split())
arr = list(map(int, input().split()))

pq = []

for i in range(n):
    heapq.heappush(pq, -arr[i])

for _ in range(m):
    curr = -heapq.heappop(pq)
    heapq.heappush(pq, -(curr-1))

print(-pq[0])