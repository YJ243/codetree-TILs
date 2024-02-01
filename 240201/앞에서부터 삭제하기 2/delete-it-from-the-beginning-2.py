import heapq
n = int(input())
arr = list(map(int, input().split()))

total = sum(arr)

# 초깃값 처리
ans = 0
pq = []
cur_sum, cur_avg, cur_min = arr[n-1]+arr[n-2],0,0
# 뒤의 두 개 값을 우선순위 큐에 넣기
heapq.heappush(pq, arr[n-1])
heapq.heappush(pq, arr[n-2])
cur_min = heapq.heappop(pq)     # 현재까지 중 최솟값 빼기
heapq.heappush(pq, cur_min)


cur_avg = (cur_sum-cur_min) // (len(pq)-1)  # 남아있는 수 중 가장 작은 숫자 빼고 평균 구하기
ans = max(ans, cur_avg)

for k in range(n-3, 0, -1):
    # k번재 숫자 보기
    cur_sum += arr[k]
    heapq.heappush(pq, arr[k])

    if cur_min > arr[k]:
        cur_min = arr[k]
    cur_avg = (cur_sum-cur_min) // (len(pq)-1)
    ans = max(ans, cur_avg)
print(f"{ans:.2f}")