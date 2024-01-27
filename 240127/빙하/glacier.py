from collections import deque

n, m = tuple(map(int, input().split()))
grid = [list(map(int, input().split())) for _ in range(n)]
tmp = [[0 for _ in range(m)] for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]
dirs = ((1,0),(0,1),(-1,0),(0,-1))
q = deque()

melt_cnt = 0
elapsed_time = 0

def Initialize_visited():
    for i in range(n):
        for j in range(m):
            visited[i][j] = False

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < m

# 범위 안에 있고, 방문하지 않았어야 함, 그리고 이전의 좌표가 0이어야 하고, 방문했어야 함
def CanGo(nx,ny, px, py): 
    return InRange(nx,ny) and not visited[nx][ny] and not grid[px][py] and visited[px][py]

def bfs():
    global melt_cnt
    while q:
        x, y = q.popleft()
        for d in range(4):
            nx, ny = x+dirs[d][0], y+dirs[d][1]
            if CanGo(nx, ny, x, y):
                visited[nx][ny] = True
                q.append((nx,ny))
                if grid[nx][ny]:
                    melt_cnt += 1

def Melt_glacier():
    for i in range(n):
        for j in range(m):
            if visited[i][j] and grid[i][j]:
                grid[i][j] = 0

def IsFinish():
    for i in range(n):
        for j in range(m):
            if grid[i][j]:
                return False
    return True

while True:
    elapsed_time += 1          # 1초 증가
    Initialize_visited()    # 방문 배열 초기화
    melt_cnt = 0            # 현재 턴에서 녹은 빙하 개수 초기화
    
    visited[0][0] = True
    q.append((0,0))
    bfs()                   # 탐색 진행

    Melt_glacier()          # 빙하 녹이기
    if IsFinish():
        break


print(elapsed_time, melt_cnt)

''' 해설 '''
'''
from collections import deque
import enum

class Element(enum.Enum):
    WATER = 0
    GLACIER = 1

# 변수 선언 및 입력
n, m = tuple(map(int, input().split()))

a = [
    list(map(int, input().split()))
    for _ in range(n)
]

# bfs에 필요한 변수들 입니다.
q = deque()
glaciers_to_melt = deque()
visited = [
    [False for _ in range(m)]
    for _ in range(n)
]
cnt = 0

# 0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
dxs, dys = [0, 1, 0, -1], [1, 0, -1, 0]

# 소요 시간과 가장 마지막으로 녹은 빙하의 수를 저장합니다.
elapsed_time = 0
last_melt_cnt = 0

# 주어진 위치가 격자를 벗어나는지 여부를 반환합니다.
def in_range(x, y):
    return 0 <= x and x < n and 0 <= y and y < m

# 범위를 벗어나지 않으면서 물이여야 하고 방문한적이 
# 없어야 갈 수 있습니다.
def can_go(x, y):
    return in_range(x, y) and a[x][y] == Element.WATER.value and not visited[x][y]

def is_glacier(x, y):
    return in_range(x, y) and a[x][y] == Element.GLACIER.value and not visited[x][y]

# visited 배열을 초기화합니다.
def initialize():
    for i in range(n):
        for j in range(m):
            visited[i][j] = False

# 빙하에 둘러쌓여 있지 않은 물들을 전부 구해주는 BFS입니다.
# 문제에서 가장자리는 전부 물로 주어진다 했기 때문에
# 항상 (0, 0)에서 시작하여 탐색을 진행하면
# 빙하에 둘러쌓여 있지 않은 물들은 전부 visited 처리가 됩니다.
def bfs():
    # BFS 함수가 여러 번 호출되므로
    # 사용하기 전에 visited 배열을 초기화 해줍니다.
    initialize()
    
    # 항상 (0, 0)에서 시작합니다.
    q.append((0, 0))
    visited[0][0] = True
    
    while q:
        # queue에서 가장 먼저 들어온 원소를 뺍니다.
        x, y = q.popleft()
        
        # queue에서 뺀 원소의 위치를 기준으로 네 방향을 확인합니다.
        for dx, dy in zip(dxs, dys):
            new_x, new_y = x + dx, y + dy

            # 더 갈 수 있는 곳이라면 Queue에 추가합니다.
            if can_go(new_x, new_y):
                q.append((new_x, new_y))
                visited[new_x][new_y] = True


# 현재 위치를 기준으로 인접한 영역에
# 빙하에 둘러쌓여 있지 않은 물이 있는지를 판단합니다.   
def outside_water_exist_in_neighbor(x, y):
    for dx, dy in zip(dxs, dys):
        new_x, new_y = x + dx, y + dy
        if in_range(new_x, new_y) and visited[new_x][new_y]:
            return True
        
    return False

# 인접한 영역에 빙하에 둘러쌓여 있지 않은 물이 있는 빙하를 찾아
# 녹여줍니다.
def melt():
    global last_melt_cnt
    
    for i in range(n):
        for j in range(m):
            if a[i][j] == Element.GLACIER.value and \
                    outside_water_exist_in_neighbor(i, j):
                a[i][j] = Element.WATER.value
                last_melt_cnt += 1

# 빙하를 한 번 녹입니다.
def simulate():
    global elapsed_time, last_melt_cnt
    
    elapsed_time += 1
    last_melt_cnt = 0
    
    # 빙하에 둘러쌓여 있지 않은 물의 위치를 전부
    # visited로 체크합니다.
    bfs()
    
    # 인접한 영역에 빙하에 둘러쌓여 있지 않은 물이 있는 빙하를 찾아
    # 녹여줍니다.
    melt()

# 빙하가 아직 남아있는지 확인합니다.
def glacier_exist():
    for i in range(n):
        for j in range(m):
            if a[i][j] == Element.GLACIER.value:
                return True
    return False
    
while True:
    simulate()
    
    # 빙하가 존재하는 한 계속 빙하를 녹입니다.
    if not glacier_exist():
        break
        
print(elapsed_time, last_melt_cnt)
'''