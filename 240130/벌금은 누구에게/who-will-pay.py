MAX_N = 100
n, m, k = map(int, input().split())     # n명 학생, m번에 걸쳐 벌칙에 걸린 학생 번호, k번 이상 벌칙 받으면 벌금

penalty_cnt = [0 for _ in range(MAX_N+1)]

ans = -1
def IsFine():
    global ans

    #print(penalty_cnt)
    for i in range(1, n+1):
        if penalty_cnt[i] >= k:
            ans = i
            return True
    return False

for _ in range(m):
    num = int(input())
    penalty_cnt[num] += 1

    if IsFine():
        break

print(ans)