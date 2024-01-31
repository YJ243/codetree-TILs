# N명 개발자, K번까지만 감염 가능, P번 사람 초기 감염, T번에 걸쳐 악수
N, K, P, T = tuple(map(int, input().split()))

IsInfected = [0 for _ in range(N+1)]        # IsInfected[i]: i번 사람이 감염되었는가
Infection_Left = [0 for _ in range(N+1)]    # Infection_Left[i]: i번 사람이 감염시킬 수 있는 횟수

hand_shake = [list(map(int, input().split())) for _ in range(T)]    # 각 사람이 악수한 시간, 악수한 두 사람의 번호
hand_shake.sort(key=lambda x: x[0])                                 # 악수한 시간 순대로 오름차순 정렬

IsInfected[P] = 1           # 초기 감염자 감염 표시
Infection_Left[P] = K       # 전염시킬 수 있는 횟수 업데이트

for turn in hand_shake:
    x, y = turn[1], turn[2]
    # 1. 만약 첫번째 사람이 감염이 되었고, 아직 전염시킬 횟수가 남아있으면서, 두번째 사람이 감염되지 않았다면
    if IsInfected[x] and Infection_Left[x] > 0 and not IsInfected[y]:
        IsInfected[y] = 1
        Infection_Left[x] -= 1
        Infection_Left[y] = K
    # 2. 1과 반대의 경우
    elif IsInfected[y] and Infection_Left[y] > 0 and not IsInfected[x]:
        IsInfected[x] = 1
        Infection_Left[y] -= 1
        Infection_Left[x] = K
    # 3. 둘다 감염된 경우
    elif IsInfected[x] and IsInfected[y]:
        # 만약 첫번째 사람의 전염 가능 횟수가 남아있다면
        if Infection_Left[x] > 0:
            Infection_Left[x] -= 1
        # 만약 두번째 사람의 전염 가능 횟수가 남아있다면
        if Infection_Left[y] > 0:
            Infection_Left[y] -= 1

# 출력:
for i in range(1, N+1):
    print(IsInfected[i], end='')

''' 해설 '''
'''
# 클래스 선언:
class Shake:
    def __init__(self, time, person1, person2):
        self.time, self.person1, self.person2 = time, person1, person2

# 변수 선언 및 입력
n, k, p, t = tuple(map(int, input().split()))	
shakes = []
for _ in range(t):
    time, person1, person2 = tuple(map(int, input().split()))
    shake.append(Shake(time, person1, person2))

shake_num = [0] * (n+1)
infected = [False] * (n+1)

infected[p] = True

# Custom Comparator를 활용한 정렬
shakes.sort(key = lambda x: x.time)

# 각 악수 횟수를 세서,
# k번 초과로 악수를 했을 시 전염시키지 않음
for shake in shakes:
    target1 = shake.person1
    target2 = shake.person2


    # 감염되어 있을 경우 악수 횟수를 증가시킴
    if infected[target1]:
        shake_num[target1] += 1
    if infected[target2]:
        shake_num[target2] += 1
    
    # target1이 감염되어 있고, 아직 k번 이하로 악수했다면 target2를 전염시킴
    if shake_num[target1] <= k and infected[target1]:
        infected[target2] = True
    
    # target2가 감염되어 있고 아직 K번 이하로 악수했다면 target1을 전염시킵니다.
	if shake_num[target2] <= k and infected[target2]:
		infected[target1] = True

for i in range(1, n+1):
    if infected[i]:
        print(1, end="")
    else:
        print(0, end="")
'''