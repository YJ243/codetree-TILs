import heapq        # 우선순위 큐를 위한 라이브러리
n = int(input())    # 연산의 개수 입력받기

pq = []             # 우선순위 큐를 위한 변수

for _ in range(n):
    num = int(input())
    # num이 0이 아니라면 우선순위 큐에 넣어주기
    # 단, 절댓값이 작은 값부터 나오도록 (|x|, x) 형태로 넣어주기
    if num != 0:
        heapq.heappush(pq, (abs(num), num))
    
    # num이 0이라면
    # 가장 앞에 있는 원소를 출력해주고 제거
    else:
        # 우선순위 큐가 비어져 있다면 0을 출력하고 넘어가기
        if not pq:
            print(0)
        else:
            _, ans = heapq.heappop(pq)
            print(ans)