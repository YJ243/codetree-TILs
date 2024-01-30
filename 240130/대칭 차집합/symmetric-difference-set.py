cntA, cntB = tuple(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))

setA = set()
for cur in A:
    setA.add(cur)

Overlapped = 0
for cur in B:
    if cur in setA:
        Overlapped += 1

print(cntA-Overlapped + cntB-Overlapped)


''' 해설 풀이 '''
'''
# 변수 선언 및 입력:
n, m = tuple(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))

ans = n + m

# 수열 A의 원소를 전부 HashSet에 넣어주기
set1 = set(A)

# 수열 B의 각 원소가 첫 번째 수열에 들어있는지 확인
for elem2 in B:
    # 만약 들어있다면 수열 A와 수열 B에 모두 있는 값
    # 이는 대칭 차집합의 원소가 아니므로 정답의 개수에서 지워주기
    if elem2 in set1:
        ans -= 1
    
# 대칭 차집합의 원소의 개수를 출력
print(ans)
'''