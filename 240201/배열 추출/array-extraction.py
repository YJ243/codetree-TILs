import heapq

pq = [] # 변수 선언
n = int(input())
for _ in range(n):
    op = int(input())
    # x가 자연수라면 priority queue에 x를 넣기
    if op != 0:
        heapq.heappush(pq, -op)
    else:
        # x가 0이라면
        # 최댓값을 찾아 출력한 뒤 제거 
        if not pq:
            print(0)
        else:    
            print(-heapq.heappop(pq))