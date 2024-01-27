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