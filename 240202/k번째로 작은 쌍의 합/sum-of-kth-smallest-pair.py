'''
2024.2.4
두 수열 오름차순으로 정렬한 뒤,
수열 A의 각 원소마다 현재 매칭된 수열 B의 원소를 연결시켜 최대 n개의 원소를 PQ로 관리하여 해결
PQ에는 항상 최대 n개의 원소가 들어가 있기 때문에
* 삽입, 삭제에 걸리는 시간은 O(logN), 처음 PQ를 만드는데 O(NlogN), 이후 K번 최솟값 구하는데 O(KlogN),
* 처음 각 수열을 정렬하는데 O(NlogN + MlogM)이 소요 => 총 시간복잡도는 O(NlogN + MlogM + KlogN)
'''
import heapq

# 입력:
n, m, k = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 변수 선언
pq = []

# 주어진 배열을 정렬
A.sort()
B.sort()

# 처음에는 n개의 원소에 대해 각각
# 두 번째 수열의 첫 번째 원소를 대응시켜 주기
# 작은 값이 더 먼저 나와야 함
for i in range(n):
    heapq.heappush(pq, (A[i]+B[0], i, 0))   # 우선순위 큐에다 합, A인덱스, B인덱스 넣기

# 1번부터 k-1번까지 합이 작은 쌍을 골라주기
for _ in range(k-1):
    tmp_sum, A_idx, B_idx = heapq.heappop(pq)
    
    # 만약 첫번째 수열의 A_idx번째 원소와 더 매칭할 두 번째 수열의 원소가 남아있다면
    # 우선순위 큐에 넣어주기
    if B_idx+1 < m:
        heapq.heappush(pq, (A[A_idx] + B[B_idx+1], A_idx, B_idx+1))

# k번째 합을 가져
ans, _, _ = heapq.heappop(pq)
print(ans)