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