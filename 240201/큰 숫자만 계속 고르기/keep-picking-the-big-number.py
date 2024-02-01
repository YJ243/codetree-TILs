import heapq
n, m = map(int, input().split())
arr = list(map(int, input().split()))

pq = []

for i in range(n):
    heapq.heappush(pq, -arr[i])

for _ in range(m):
    curr = -heapq.heappop(pq)
    heapq.heappush(pq, -(curr-1))

print(-pq[0])

''' 해설 '''
'''
import heapq

# 변수 선언 및 입력:
n, m = tuple(map(int, input().split()))
arr = list(map(int, input().split()))
pq = []

# priority queue에
# 숫자들을 넣어줍니다.
# 최댓값을 구해야 하므로
# -를 붙여서 넣어줍니다.
for elem in arr:
    heapq.heappush(pq, -elem)

# m번에 걸쳐서 
# 최댓값을 찾아 1씩 빼주는 것을 반복합니다.
for _ in range(m):
    # 최댓값을 찾고 제거합니다.
    max_val = -heapq.heappop(pq)
    # 1 뺀 값을 다시 넣어줍니다.
    # -를 붙여서 넣어줘야 함에 유의합니다.
    heapq.heappush(pq, -(max_val - 1))

print(-heapq.heappop(pq))
'''