from collections import deque
n, k = tuple(map(int, input().split()))     # 격자 크기 n, 초기 상해잇는 귤 개수 k
grid = [list(map(int, input().split())) for _ in range(n)]



temp = [row[:] for row in grid]             # 중간에 정보를 저장하는 임시 격자

q = deque()     # bfs 탐색을 위한 큐
visited = [[False for _ in range(n)] for _ in range(n)]     # 방문했는지 확인
step = [[-1 for _ in range(n)] for _ in range(n)]           # 초기 상해있는 귤로부터 상하는데 걸리는 시간
cur_rotten = 0

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(nx,ny, px, py):   # 범위 안에 있고 방문하지 않았으며, 그 이전 위치가 2인 경우
    return InRange(nx,ny) and not visited[nx][ny] and grid[px][py] == 2

def Push(x, y, val):
    step[x][y] = val
    visited[x][y] = True
    q.append((x,y))

def bfs():
    global cur_rotten
    cur_rotten = -1
    while q:
        x, y = q.popleft()      # 현재 보고 있는 좌표
        # 상하좌우 네 방향 확인하기
        dxs, dys = [1,0,-1,0], [0,1,0,-1]
        
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy     # 다음 좌표
            if InRange(nx,ny) and not visited[nx][ny]:      # 만약 범위 안에 있다면
                if grid[nx][ny] == 2:   # 근데 그 다음 값이 2라면
                    visited[nx][ny] = True  # 방문 표시
                    q.append((nx,ny))
                elif grid[nx][ny] == 1:
                    if CanGo(nx,ny, x, y):
                        Push(nx,ny, step[x][y]+1)
                        temp[nx][ny] = 2
                        cur_rotten += 1

def Make_spoil():
    global grid
    while(True):
        # 만약 현재 턴에서 상한 귤 수가 0이라면
        if cur_rotten == -1:
            break;  # 더이상 상할 귤이 없으니 break
        
        rotted = [(i,j) for i in range(n) for j in range(n) if grid[i][j] == 2]

        # 먼저 k개의 상한 귤을 큐에 넣기
        for r in rotted:
            if step[r[0]][r[1]] == -1:
                Push(r[0], r[1], 0)
            else:
                Push(r[0], r[1], step[r[0]][r[1]])

        # 그 다음 bfs()탐색 수행
        bfs()

        # temp를 grid로 옮기기
        grid = [row[:] for row in temp]


Make_spoil()
for i in range(n):
    for j in range(n):
        if grid[i][j] == 1 and not visited[i][j]:
            step[i][j] = -2

for i in range(n):
    for j in range(n):
        print(step[i][j], end= ' ')
    print()

''' 해설 '''
'''
from collections import deque

# 변수 선언 및 입력
n, k = tuple(map(int, input().split()))
a = [
    list(map(int, input().split()))
    for _ in range(n)
]

s_pos = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if a[i][j] == 2
]

# bfs에 필요한 변수들 입니다.
q = deque()
visited = [
    [False for _ in range(n)]
    for _ in range(n)
]
step = [                  # step[i][j] : 
    [0 for _ in range(n)] # (i, j) 지점에 있는 귤이 
    for _ in range(n)     # 최초로 상하게 되는 시간을 기록합니다.
]


def in_range(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

# 격자를 벗어나지 않으면서, 해당 위치에 귤이 놓여있고, 아직 방문한 적이 없는 곳이라면
# 지금 이동하는 것이 최초로 해당 귤을 상하게 하는 것이므로 가야만 함
def can_go(x, y):
    return in_range(x, y) and a[x][y] and not visited[x][y]

# queue에 새로운 위치를 추가하고
# 방문 여부를 표시해줍니다.
# 상하게 되는 시간 값도 갱신해줍니다.
def push(nx, ny, new_step):
    q.append((nx, ny))
    visited[nx][ny] = True
    step[nx][ny] = new_step

# bfs를 통해 각 칸마다 최초로 상하게 되는 시간을 구합니다.
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
                # 시간은 이전 시간에 1이 더해지게 됩니다. 
                push(nx, ny, step[x][y] + 1)

# 처음 상해있던 귤들을 전부 queue에 넣어놓고 시작
# 이는 각 칸에 있는 신선한 귤에 대해
# 가장 가까이에 있던 상한 귤로부터 최초로 상하게 되는 시간을
# 단 한 번의 bfs로 가능하게끔 함
for x, y in s_pos:
    push(x, y, 0)

bfs()

for i in range(n):
    for j in range(n):
        if a[i][j] == 0:
            print(-1, end=" ")
        else:
            if not visited[i][j]:
                print(-2, end=" ")
            else:
                print(step[i][j], end=" ")
    print()
    '''