import heapq
n = int(input())
arr = list(map(int, input().split()))

total = sum(arr)

ans = 0
for k in range(n-2, 0, -1):
    # k개 만큼 앞에서부터 삭제하기( 큰 순에서 작은 순으로)
    tmp_total = total
    for i in range(k):
        tmp_total -= arr[i]

    pq = []
    # 삭제하고 남은 나머지들을 pq에 넣기
    for i in range(k, n):
        heapq.heappush(pq, arr[i])
    tmp_total -= heapq.heappop(pq)
    
    # 평균 구하기
    avg = tmp_total / len(pq)
    ans = max(ans, avg)

print(f"{ans:.2f}")