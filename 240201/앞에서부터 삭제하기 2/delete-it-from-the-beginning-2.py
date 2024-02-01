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


cur_avg = (cur_sum-cur_min) / (len(pq)-1)  # 남아있는 수 중 가장 작은 숫자 빼고 평균 구하기
ans = max(ans, cur_avg)

for k in range(n-3, 0, -1):
    # k번재 숫자 보기
    cur_sum += arr[k]
    heapq.heappush(pq, arr[k])

    if cur_min > arr[k]:
        cur_min = arr[k]
    cur_avg = (cur_sum-cur_min) / (len(pq)-1)
    ans = max(ans, cur_avg)
print(f"{ans:.2f}")

''' 해설 '''
'''
import heapq


# 입력:
n = int(input())
arr = list(map(int, input().split()))

# 변수 선언
sum_val = 0
max_avg = 0
pq = []

heapq.heappush(pq, arr[n-1])
sum_val += arr[n-1]

# k가 N-2일 때부터 1일 때까지 거꾸로 탐색
# PQ를 이용해서 진행
for i in range(n-2, 0, -1):
    # 앞에서부터 K개를 삭제하고 나면
    # 뒤에 i ~ n-1까지의 숫자만이 남음
    heapq.heappush(pq, arr[i])
    sum_val += arr[i]

    # 남아있는 정수 중 가장 작은 숫자를 찾아 그 숫자를 제외한 평균을 구하기
    min_num = pq[0]
    avg = (sum_val - min_num) / (n-i-1)

    # 평균이 최대가 된다면 정답을 현재 평균으로 갱신
    max_avg = max(max_avg, avg)

# 평균값의 최대를 출력
print(f"{max_avg:.2f}")
'''