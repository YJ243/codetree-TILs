import heapq
n = int(input())
arr = list(map(int, input().split()))

pq = []
for num in arr:
    heapq.heappush(pq, -num)

while len(pq) != 1:
    first = -heapq.heappop(pq)
    second = -heapq.heappop(pq)

    if first == second: continue

    heapq.heappush(pq, -abs(first-second))

print(-heapq.heappop(pq))