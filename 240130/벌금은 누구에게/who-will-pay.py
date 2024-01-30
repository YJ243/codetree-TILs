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


''' 해설 '''
'''
# 변수 선언 및 입력
n, m, k = tuple(map(int, input().split()))
penalized_person = [
    int(input())
    for _ in range(m)1
]
penalty_num = [0] * (n+1)

# 각 패널티 횟수를 세서,
# 최초로 k번 이상 벌칙을 받는 사람을 추적하기
ans = -1
for target in penalized_person:
    penalty_num[target] += 1

    if penalty_num[target] >= k:
        ans = target
        break
print(ans)
'''