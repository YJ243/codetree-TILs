import heapq

# 입력:
n = int(input())
arr = list(map(int, input().split()))

# 변수 선언
pq = []

# priority queue에 숫자들을 넣어주기
for num in arr:
    heapq.heappush(pq, -num)

# 마지막 숫자가 남을 때까지 가장 큰 숫자 2개를 뽑아 제거하고
# 그 차이를 다시 집어넣기
while True:
    if len(pq) <= 1:
        break
    # 가장 큰 숫자 2개를 뽑고 제거
    first = -heapq.heappop(pq)
    second = -heapq.heappop(pq)

    # 두 숫자의 차이를 다시 넣음, 만약 0이라면 넣지 않기
    if first == second: continue

    heapq.heappush(pq, -abs(first-second))

# 마지막으로 남은 숫자가 정확히 하나라면 그 숫자를 출력
# 아무 숫자도 남지 않으면 -1을 출력 
if not pq:
    print(-1)
else:
    print(-heapq.heappop(pq))