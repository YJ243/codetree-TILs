import heapq

pq = []

n = int(input())

# priority queue를 이용하여 진행
for _ in range(n):
    inp = int(input())
    # 0이 아니라면, 해당 숫자를 priority queue에 넣어주기
    if inp != 0:
        heapq.heappush(pq, inp)
    # 0이라면 가장 작은 값을 출력하고 배열에서 제거
    else:
        # 배열이 비어있다면 0을 출력
        if not pq:
            print(0)
        # 그렇지 않다면 최솟값을 제거
        else:
            print(heapq.heappop(pq))