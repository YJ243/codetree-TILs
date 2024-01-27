from collections import deque

n, h, m = tuple(map(int, input().split()))      # n: 격자 크기, h: 사람 명수, m: 비를 피할 수 있는 공간 위치 개수
grid = [list(map(int, input().split())) for _ in range(n)]  # 0: 이동 가능한 곳, 1: 벽, 2: 사람. 3: 비를 피할 수 있는 공간
visited = [[False for _ in range(n)] for _ in range(n)]     # 방문했는지 확인하는 배열
step = [[0 for _ in range(n)] for _ in range(n)]            # 쉘터로부터 탐색 진행했을 때의 최단 거리
result = [[0 for _ in range(n)] for _ in range(n)]          # 정답 배열

dxs, dys = [1,-1,0,0], [0,0,1,-1]       # 방향
q = deque()     # 탐색을 위한 큐

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x, y):
    return InRange(x,y) and not visited[x][y] and grid[x][y] != 1

def Push(x,y,val):
    step[x][y] = val
    visited[x][y] = True
    q.append((x,y))

def bfs():
    while q:
        x, y = q.popleft()
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            if CanGo(nx,ny):    # 만약 갈 수 있다면
                Push(nx,ny, step[x][y]+1)
    
# shelter를 모두 큐에 넣기
for i in range(n):
    for j in range(n):
        if grid[i][j] == 3:
            Push(i,j,0)

bfs()

for i in range(n):
    for j in range(n):
        if grid[i][j] == 2:
            if step[i][j]:
                result[i][j] = step[i][j]
            else:
                result[i][j] = -1

for i in range(n):
    for j in range(n):
        print(result[i][j], end = ' ')
    print()

''' 해설 '''
'''
from collections import deque

# 변수 선언 및 입력
n, h, m = tuple(map(int, input().split()))
a = [
    list(map(int, input().split()))
    for _ in range(n)
]

s_pos = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if a[i][j] == 3
]

# bfs에 필요한 변수들 입니다.
q = deque()
visited = [
    [False for _ in range(n)]
    for _ in range(n)
]
step = [                    # step[i][j] : 시작점으로부터 
    [0 for _ in range(n)]   # (i, j) 지점에 도달하기 위한 
    for _ in range(n)       # 최단거리를 기록합니다.
]


def in_range(x, y):
    return 0 <= x and x < n and 0 <= y and y < n


# 격자를 벗어나지 않으면서, 벽도 없고, 아직 방문한 적이 없는 곳이라면
# 지금 이동하는 것이 최단거리임을 보장할 수 있으므로 가야만 합니다. 
def can_go(x, y):
    return in_range(x, y) and a[x][y] != 1 and not visited[x][y]


# queue에 새로운 위치를 추가하고
# 방문 여부를 표시해줍니다.
# 시작점으로 부터의 최단거리 값도 갱신해줍니다.
def push(nx, ny, new_step):
    q.append((nx, ny))
    visited[nx][ny] = True
    step[nx][ny] = new_step


# bfs를 통해 최소 이동 횟수를 구합니다.
def bfs():
    # queue에 남은 것이 없을때까지 반복합니다.
    while q:
        # queue에서 가장 먼저 들어온 원소를 뺍니다.
        x, y = q.popleft()

        dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1]

        # queue에서 뺀 원소의 위치를 기준으로 4방향을 확인해봅니다.
        for dx, dy in zip(dxs, dys):
            nx, ny = x + dx, y + dy

            # 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            # 새로 queue에 넣어줍니다.
            if can_go(nx, ny):
                # 최단 거리는 이전 최단거리에 1이 증가하게 됩니다. 
                push(nx, ny, step[x][y] + 1)


# 비를 피할 수 있는 공간들을 전부 시작점으로 하는
# bfs를 진행합니다.
# 이는 각 사람마다 가장 가까운 쉘터까지의 거리를 
# 단 한번의 bfs로 구할 수 있도록 합니다.
for x, y in s_pos:
    push(x, y, 0)

bfs()

for i in range(n):
    for j in range(n):
        if a[i][j] != 2:
            print(0, end=" ")
        else:
            if not visited[i][j]:
                print(-1, end=" ")
            else:
                print(step[i][j], end=" ")
    print()
'''