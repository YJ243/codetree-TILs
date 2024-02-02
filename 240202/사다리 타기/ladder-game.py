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

''' 해설 '''
'''
# 변수 선언 및 입력:
n, m = tuple(map(int, input().split()))

lines = list()
selected_lines = list()

ans = m

# 처음 상황과, 선택한 가로줄만 사용했을 때의 상황을 시뮬레이션하여
# 둘의 결과가 같은지 확인하기
def possible():
    # Step 1. 시작 숫자를 셋팅
    num1, num2 = [i for i in range(n)], [i for i in range(n)]

    # Step 2. 위에서부터 순서대로 적혀있는 
    # 가로줄에 대해 양쪽 번호에 해당하는 숫자를 바꿔줌
    for _, idx in lines:
        num1[idx], num1[idx+1] = num1[idx+1], num1[idx]
    for _, idx in selected_lines:
        num2[idx], num2[idx+1] = num2[idx+1], num2[idx]
    
    # Step 3. 두 상황의 결과가 동일한지 확인
    for i in range(n):
        if num1[i] != num2[i]:
            return False
    return True

def find_min_lines(cnt):
    global ans

    if cnt == m:
        if possible():
            ans = min(ans, len(selected_lines))
        return
    selected_lines.append(lines[cnt])
    find_min_lines(cnt+1)
    selected_lines.pop()

    find_min_lines(cnt+1)

for _ in range(m):
    a, b = tuple(map(int, input().split()))
    lines.append((b, a-1))

lines.sort()

find_min_lines(0)
print(ans)
'''