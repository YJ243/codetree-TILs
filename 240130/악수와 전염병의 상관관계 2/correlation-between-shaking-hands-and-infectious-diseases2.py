# N명 개발자, K번까지만 감염 가능, P번 사람 초기 감염, T번에 걸쳐 악수
N, K, P, T = tuple(map(int, input().split()))

IsInfected = [0 for _ in range(N+1)]        # IsInfected[i]: i번 사람이 감염되었는가
Infection_Left = [0 for _ in range(N+1)]    # Infection_Left[i]: i번 사람이 감염시킬 수 있는 횟수

hand_shake = [list(map(int, input().split())) for _ in range(T)]
hand_shake.sort(key=lambda x: x[0])         # 악수한 시간 순대로 정렬

IsInfected[P] = 1           # 초기 감염자 감염 표시
Infection_Left[P] = K       # 전염시킬 수 있는 횟수 업데이트

for turn in hand_shake:
    x, y = turn[1], turn[2]
    if IsInfected[x] and Infection_Left[x] > 0 and not IsInfected[y]:
        IsInfected[y] = 1
        Infection_Left[x] -= 1
        Infection_Left[y] = K
    elif IsInfected[y] and Infection_Left[y] > 0 and not IsInfected[x]:
        IsInfected[x] = 1
        Infection_Left[y] -= 1
        Infection_Left[x] = K
    elif IsInfected[x] and IsInfected[y]:
        if Infection_Left[x] > 0:
            Infection_Left[x] -= 1
        if Infection_Left[y] > 0:
            Infection_Left[y] -= 1

for i in range(1, N+1):
    print(IsInfected[i], end='')