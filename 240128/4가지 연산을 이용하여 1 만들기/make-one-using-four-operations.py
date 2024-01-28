from collections import deque

N = int(input())    # 숫자 N이 주어짐

q = deque()
cnt = 0
step = [0 for _ in range(2*N+1)]
visited = [ False for _ in range(2*N+1)]

def Push(num, operation_cnt):
    visited[num] = True
    step[num] = operation_cnt
    q.append(num)

def MakeOne():
    global cnt
    while q:
        cur = q.popleft()
        if cur == 1:    # 만약 숫자 1이 나왔다면 cnt 업데이트하고 반복문 나가기
            cnt = step[cur]
            break

        # 이제 4가지 연산을 사용할 수 있는지 보기
        if cur % 2 == 0 and not visited[cur//2]:
            # 만약 2로 나누어떨어진다면
            Push(cur//2, step[cur]+1)
        if cur % 3 == 0 and not visited[cur//3]:
            Push(cur // 3, step[cur]+1)
        if not visited[cur+1]:
            Push(cur+1, step[cur]+1)
        if not visited[cur-1]:
            Push(cur-1, step[cur]+1)

                 

Push(N, 0)
MakeOne()
print(cnt)

''' 해설 '''
'''
from collections import deque
import sys
import enum

OPERATOR_NUM = 4
INT_MAX = sys.maxsize

class OPERATOR(enum.Enum):
    SUBTRACT = 0
    ADD = 1
    DIV2 = 2
    DIV3 = 3

n = int(input())
ans = INT_MAX

q = deque()
visited = [False for _ in range(2*n)]

# step[i]: 정점 n에서 시작하여 정점 i지점에 도달하기 위한 최단거리를 기록
step = [0 for _ in range(2*n)]

# num이라는 값에 해당 operator를 사용할 수 있는지를 판단하기
# 2로 나누거나 3으로 나누려는 경우 num이 해당 값으로 나누어 떨어질 때에만 해당 연산을 사용 가능
def possible(num, op):
    if op == OPERATOR.SUBTRACT.value or op == OPERATOR.ADD.value:
        return True
    elif op == OPERATOR.DIV2.value:
        return num % 2 == 0
    else:
        return num % 3 == 0

# num에 op 연산을 수행했을 때의 결과를 반환
def calculate(num, op):
    if op == OPERATOR.SUBTRACT.value:
        return num-1
    elif op == OPERATOR.ADD.value:
        return num+1
    elif op == OPERATOR.DIV2.value:
        return num // 2
    else
        return num // 3

# 1에서 2n-1 사이의 숫자만 이용해도 올바른 답을 구할 수 있으므로
# 그 범위 안에 들어오는 숫자인지 확인
def in_range(num):
    return 1 <= num and num <= 2*n-1

# 1에서 2n-1 사이의 숫자이면서 아직 방문한 적이 없다면 가야함
def can_go(num):
    return in_range(num) and not visited[num]

# queue에 새로운 위치를 추가하고 방문 여부를 표시해주기
# 시작점으로부터의 최단거리 값도 갱신
def push(num, new_step):
    q.append(num)
    visited[num] = True
    step[num] = new_step

# BFS를 통해 최소 연산 횟수를 구하기
def find_min():
    global ans
    # queue에 남은 것이 없을 때까지 반복
    while q:
        # queue에서 가장 먼저 들어온 원소를 빼기
        curr_num = q.popleft()

        # queue에서 뺀 원소의 위치를 기준으로 4가지 연산 적용해보기
        for i in range(OPERATOR_NUM):
            # 연산을 적용할 수 없는 경우라면 패스하기
            if not possible(curr_num, i):
                continue
            
            new_num = calculate(curr_num, i)
            # 아직 방문한 적이 없으면서 갈 수 있는 곳이라면 새로 queue에 넣어주기
            if can_go(new_num):
                # 최단 거리는 이전 거리에 1이 증가
                push(new_num, step[curr_num] + 1)
        
        # 1번 정점까지 가는 데 필요한 최소 연산 횟수를 답으로 기록
        ans = step[1]

# BFS를 통해 최소 연산 횟수를 구하기
push(n,0)
find_min()
print(ans)
'''