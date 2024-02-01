import heapq

t = int(input())        # 테스트 케이스 개수
for _ in range(t):      # 각 테스트 케이스 마다 
    m = int(input())    # 수열의 크기
    arr = list(map(int, input().split()))   # 수열 입력받기
    medium = arr[0]     # 첫번째 값을 처음의 중앙값으로 설정
    print(medium, end=' ')
    minheap = []        # 중앙값보다 큰 수들 배열, 가장 작은 값을 반환하도록
    maxheap = []        # 중앙값보다 작은 수들 배열, 가장 큰 값을 반환하도록

    for i in range(1, m):   # 두번째 값부터 맨 끝까지 확인하기
        if i % 2 == 1:      # 짝수번째 값 확인
            # 이때는 중앙값과 비교해서 작으면 maxheap에, 크면 minheap에 넣어주면 됨
            if arr[i] <= medium:
                heapq.heappush(maxheap, -arr[i])
            else:
                heapq.heappush(minheap, arr[i])
        else:               # 홀수번째 값 확인
            # 확인할 후보는 medium, arr[i], 두 PQ중 더 많은 값을 가진 큐에서 우선순위가 가장 큰 값

            checking = 0
            if len(minheap) > len(maxheap):
                checking = heapq.heappop(minheap)
            else:
                checking = -heapq.heappop(maxheap)
            
            tmp = sorted([checking, medium, arr[i]])    # 정렬해서 첫번째 값은 maxheap, 두번째는 medium, 세번째는 minheap으로

            heapq.heappush(maxheap, -tmp[0])
            medium = tmp[1]
            heapq.heappush(minheap, tmp[2])

            print(medium, end=' ')
    
    print()


''' 해설 '''
'''
import heapq

# 변수 선언 및 입력:
t = int(input())
arr = []

def find_median():
    # 중앙값(median)을 계속 관리해준다
    # 중앙값보다 작은 숫자들을 max heap으로 관리하여 (max_pq)
    # 중앙값보다 큰 숫자들을 min heap으로 관리하여 (min_pq)
    # 새로운 숫자가 추가될 때마다 그에 따라 median, max_pq, min_pq를 업데이트 해주기
    median = arr[0]
    max_pq, min_pq = [], []
    print(median, end=" ")

    for i in range(1, m):
        # Case 1.
        # 짝수 번째에 새로운 숫자가 주어졌을 경우에는
        # 양쪽 max_pq, min_pq에 들어있는 원소의 수가
        # 정확히 동일할 것이므로 중앙값은 그대로 두고
        # median과 arr[i]값을 비교하여
        # arr[i] < median이라면 max_pq에, arr[i] > median이라면 min_pq에 넣어주기
        if i % 2 == 1:
            if arr[i] < median:
                heapq.heappush(max_pq, -arr[i])
            else:
                heapq.heappush(min_pq, arr[i])
        
        # Case 2.
        # 홀수 번째에 새로운 숫자가 주어졌을 경우에는
        # max_pq, min_pq 중 개수가 1개 더 많은 곳이
        # 어디인지에 따라 다른 전략을 취해주기
        else:
            # Step 1.
            # 먼저 max_pq, min_pq 중 개수가 1개 더 많은 곳에서 우선순위가 가장 큰 값을 뽑아주기
            # 이를 new_cand로 
            if len(max_pq) > len(min_pq):
                new_cand = -heapq.heappop(max_pq)
            else:
                new_cand = heapq.heappop(min_pq)

            # Step 2.
            # 이제 max_pq, min_pq에 들어있는 숫자의 개수는 정확히 동일
            # median, arr[i], new_cand에서 가장 작은 값은 max_pq, 중앙값은 median, 가장 큰 값은 min_pq에 넣어주기
            # 정렬을 이용해 편하게 구현하기
            nums = sorted([median, arr[i], new_cand])

            # 순서대로 값을 넣어주기
            heapq.heappush(max_pq, -nums[0])
            median = nums[1]
            heapq.heappush(min_pq, nums[2])

            # 홀수 번째의 경우에는 중앙값을 출력하기
            print(median, end=' ')

    print()

for _ in range(t):
    m = int(input())
    arr = list(map(int, input().split()))

    # 홀수 번째마다 중앙값을 찾는 것을 반복
    find_median()
'''