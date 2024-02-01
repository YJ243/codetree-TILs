import heapq
n = int(input())
arr = list(map(int, input().split()))

pq = []
for num in arr:
    heapq.heappush(pq, -num)


while True:
    if len(pq) <= 1:
        break

    first = -heapq.heappop(pq)
    second = -heapq.heappop(pq)

    if first == second: continue

    heapq.heappush(pq, -abs(first-second))

if not pq:
    print(-1)
else:
    print(-heapq.heappop(pq))