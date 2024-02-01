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