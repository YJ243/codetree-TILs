n = int(input())
arr = [list(map(int, input().split())) for _ in range(4)]

freqAB = dict()
freqCD = dict()

for i in range(n):
    for j in range(n):
        if arr[0][i] + arr[1][j] not in freqAB:
            freqAB[arr[0][i]+arr[1][j]] = 1
        else:
            freqAB[arr[0][i]+arr[1][j]] += 1

        if arr[2][i]+arr[3][j] not in freqCD:
            freqCD[arr[2][i]+arr[3][j]] = 1
        else:
            freqCD[arr[2][i]+arr[3][j]] += 1
ans = 0

freqAB_arr = [[key, value] for key, value in freqAB.items()]

for i in range(len(freqAB_arr)):
    if -freqAB_arr[i][0] in freqCD:
        ans += freqCD[-freqAB_arr[i][0]] * freqAB[freqAB_arr[i][0]]

print(ans)

''' 해설 '''
'''
# 변수 선언 및 입력:
n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
D = list(map(int, input().split()))

count = dict()

# A 수열에서 숫자 하나, B수열에서 숫자 하나를 골랐을 때
# 나올 수 있는 두 숫자의 합들을 hashmap에 기록하기
for i in range(n):
    for j in range(n):
        sum_val = A[i] + B[j]
        if sum_val in count:
            count[sum_val] += 1
        else:
            count[sum_val] = 1
        
# C, D 수열을 순회하며 쌍을 만들어 주기
# 앞서 계산한 hashmap을 이용하면
# C, D 수열에서 고른 값으로 A, B와 쌍을 만들 때
# 총합이 0이 되는 쌍의 개수를 쉽게 구할 수 있음
for i in range(n):
    for j in range(n):
        diff = -C[i] - D[j]

        if diff in count:
            ans += count[diff]

# 출력:
print(ans)
'''