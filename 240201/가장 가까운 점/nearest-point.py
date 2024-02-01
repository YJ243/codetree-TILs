import heapq
n, m = map(int, input().split())

points = [list(map(int, input().split())) for _ in range(n)]
pq = []

for point in points:
    heapq.heappush(pq, ((abs(point[0])+abs(point[1])), point[0], point[1]))

for _ in range(m):
    _, x, y = heapq.heappop(pq)
    x += 2
    y += 2
    heapq.heappush(pq, ((abs(x)+abs(y)), x, y))

_, x, y = heapq.heappop(pq)

print(x, y)