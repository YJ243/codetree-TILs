import heapq
n, m, k = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort()

pq = []

for i in range(n):
    heapq.heappush(pq, (A[i]+B[0], i, 0))   # 우선순위 큐에다 합, A인덱스, B인덱스 넣기

for _ in range(k-1):
    tmp_sum, A_idx, B_idx = heapq.heappop(pq)
    if B_idx+1 < m:
        heapq.heappush(pq, (A[A_idx] + B[B_idx+1], A_idx, B_idx+1))

ans, _, _ = heapq.heappop(pq)
print(ans)