import heapq

pq = []

n = int(input())

for _ in range(n):
    inp = int(input())
    if inp != 0:
        heapq.heappush(pq, inp)
    else:
        if not pq:
            print(0)
        else:
            print(heapq.heappop(pq))