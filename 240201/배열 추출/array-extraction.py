import heapq

pq = []

n = int(input())
for _ in range(n):
    op = int(input())
    if op != 0:
        heapq.heappush(pq, -op)
    else:
        if not pq:
            print(0)
        else:    
            print(-heapq.heappop(pq))