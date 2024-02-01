import heapq

# 변수 선언 및 입력
n, m = map(int, input().split())

points = [list(map(int, input().split())) for _ in range(n)]
pq = []

# priority queue에 x+y, x, y 순으로 우선순위가 되도록 함
for point in points:
    heapq.heappush(pq, ((abs(point[0])+abs(point[1])), point[0], point[1]))

# m번에 걸쳐 가장 가까운 점을 잡아 2씩 더해주는 작업을 하기
for _ in range(m):
    _, x, y = heapq.heappop(pq)

    # 그 다음 위치를 추가
    x += 2
    y += 2
    heapq.heappush(pq, ((abs(x)+abs(y)), x, y))

_, x, y = heapq.heappop(pq)

print(x, y)