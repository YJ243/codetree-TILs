n, m = map(int, input().split())
lines = [list(map(int, input().split())) for _ in range(m)]
lines.sort(key=lambda x:x[1])   # b를 기준으로 오름차순 정렬하여 위에서부터 차례대로 보도록

result = [i for i in range(1, n+1)]
result.insert(0,0)  # 구현의 편의를 위해 맨 앞에 0 추가

for i in range(m):      # 사다리를 타고 난 결과를 구하기
    idx1, idx2 = lines[i][0], lines[i][0]+1
    result[idx1], result[idx2] = result[idx2], result[idx1]

selected = []
ans = m

def IsSameResult():
    tmp = [i for i in range(1, n+1)]
    tmp.insert(0,0)

    for i in range(len(selected)):
        idx1, idx2 = selected[i][0], selected[i][0]+1
        tmp[idx1], tmp[idx2] = tmp[idx2], tmp[idx1]

    for i in range(n):
        if result[i] != tmp[i]:
            return False

    return True

def Choose(idx):
    global ans
    if idx == m:
        if IsSameResult():
            ans = min(ans, len(selected))
        return

    selected.append(lines[idx])
    Choose(idx+1)
    selected.pop()

    Choose(idx+1)

Choose(0)
print(ans)