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