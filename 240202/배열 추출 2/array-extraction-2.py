import heapq        # 우선순위 큐를 위한 라이브러리
n = int(input())    # 연산의 개수 입력받기

pq = []             # 우선순위 큐를 위한 변수

for _ in range(n):
    num = int(input())
    if num != 0:
        heapq.heappush(pq, (abs(num), num))
    else:
        if not pq:
            print(0)
        else:
            _, ans = heapq.heappop(pq)
            print(ans)