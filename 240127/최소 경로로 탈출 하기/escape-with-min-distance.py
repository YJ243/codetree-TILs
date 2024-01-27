from collections import deque

n, m = tuple(map(int, input().split()))
grid = [list(map(int, input().split())) for _ in range(n)]  # 뱀:0, 빈칸:1
step = [[0 for _ in range(m)] for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]

q = deque()

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < m

def CanGo(x, y):
    return InRange(x, y) and grid[x][y] and not visited[x][y] 

def Push(x, y, val):
    step[x][y] = val
    visited[x][y] = True
    q.append((x,y))

def bfs():
    while q:
        x, y = q.popleft()
        dxs, dys = [1,0,-1,0], [0,1,0,-1]

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            if CanGo(nx,ny):
                Push(nx,ny, step[x][y]+1)

Push(0,0,0)
bfs()

if visited[n-1][m-1]:
    print(step[n-1][m-1])
else:
    print(-1)

''' 해설 '''
'''
import sys
from collections import deque

INT_MAX = sys.maxsize

# 변수 선언 및 입력
n, m = tuple(map(int, input().split()))

a = [
    list(map(int, input().split()))
    for _ in range(n)
]

# bfs에 필요한 변수들 입니다.
q = deque()
visited = [
    [False for _ in range(m)]
    for _ in range(n)
]
# step[i][j] : 시작점으로부터 (i, j) 지점에 도달하기 위한 
# 최단거리를 기록합니다.
step = [
    [0 for _ in range(m)]
    for _ in range(n)
]

ans = INT_MAX

def in_range(x, y):
    return 0 <= x and x < n and 0 <= y and y < m


# 격자를 벗어나지 않으면서, 뱀도 없고, 아직 방문한 적이 없는 곳이라면
# 지금 이동하는 것이 최단거리임을 보장할 수 있으므로 가야만 합니다. 
def can_go(x, y):
    return in_range(x, y) and a[x][y] and not visited[x][y]


# queue에 새로운 위치를 추가하고
# 방문 여부를 표시해줍니다.
# 시작점으로 부터의 최단거리 값도 갱신해줍니다.
def push(new_x, new_y, new_step):
    q.append((new_x, new_y))
    visited[new_x][new_y] = True
    step[new_x][new_y] = new_step
    
    
# bfs를 통해 최소 이동 횟수를 구합니다.
def find_min():
    global ans
    
    dxs, dys = [0, 1, 0, -1], [1, 0, -1, 0]
    
    # queue에 남은 것이 없을때까지 반복합니다.
    while q:
        # queue에서 가장 먼저 들어온 원소를 뺍니다.
        x, y = q.popleft()    
    
        # queue에서 뺀 원소의 위치를 기준으로 4방향을 확인해봅니다.
        for dx, dy in zip(dxs, dys):
            new_x, new_y = x + dx, y + dy
        
            # 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            # 새로 queue에 넣어줍니다.
            if can_go(new_x, new_y):
                # 최단 거리는 이전 최단거리에 1이 증가하게 됩니다.
                push(new_x, new_y, step[x][y] + 1)
    
    # 우측 하단에 가는 것이 가능할때만 답을 갱신해줍니다.
    if visited[n - 1][m - 1]:
        ans = step[n - 1][m - 1]

# bfs를 이용해 최소 이동 횟수를 구합니다.
# 시작점을 queue에 넣고 시작합니다.
push(0, 0, 0)
find_min()

# 불가능한 경우라면 -1을 답으로 넣어줍니다.
if ans == INT_MAX:
    ans = -1
    
print(ans)
'''