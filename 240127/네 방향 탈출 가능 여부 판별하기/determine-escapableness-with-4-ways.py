from collections import deque

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]

q = deque()

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < m

def CanGo(x, y):
    return InRange(x,y) and grid[x][y] and not visited[x][y]

def bfs():
    while q:
        x, y = q.popleft()
        dirs = ((1,0),(0,1),(-1,0),(0,-1))
        for d in range(4):
            nx, ny = x+dirs[d][0], y+dirs[d][1]
            if CanGo(nx,ny):
                visited[nx][ny] = 1
                q.append((nx,ny))


q.append((0,0))
visited[0][0] = 1
bfs()


print(visited[n-1][m-1])