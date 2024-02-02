import heapq
n = int(input())
arr = list(map(int, input().split()))

pq = []

for i in range(n):
    heapq.heappush(pq, arr[i])
    if len(pq) < 3:
        print(-1)
    else:
        tmp = []
        for j in range(3):
            tmp.append(heapq.heappop(pq))
        curr = 1
        for j in range(3):
            curr *= tmp[j]
        print(curr)
        for j in range(3):
            heapq.heappush(pq, tmp[j])

''' 해설 '''
'''
import heapq

# 입력:
n = int(input())
arr = list(map(int, input().split()))

# 변수 선언
pq = [] 

# priority queue를 이용하여 진행합니다.
for elem in arr:
    # 해당 숫자를 priority queue에 넣어주기
    heapq.heappush(pq, elem)

    if len(pq) >= 3:
        # 주어진 수가 3개 이상이라면 가장 작은 숫자 3개의 곱을 출력
        x = heapq.heappop(pq)
        y = heapq.heappop(pq)
        z = heapq.heappop(pq)

        print(x * y * z)

        heapq.heappush(pq, x)
        heapq.heappush(pq, y)
        heapq.heappush(pq, z)
    
    else:
        # 아직 주어진 숫자의 수가 3개가 되지 않으면 -1을 출력합니다.
        print(-1)
'''