from collections import deque

n, k = tuple(map(int, input().split()))
grid = [list(map(int, input().split())) for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]
q = deque()

r, c = map(int, input().split())
r -= 1
c -= 1

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x,y,val):
    return InRange(x,y) and not visited[x][y] and grid[x][y] < val

def InitializeVisited():
    for i in range(n):
        for j in range(n):
            visited[i][j] = False

def bfs(val):
    curMax, curX, curY = 0,-1,-1
    while q:
        x, y = q.popleft()
        dxs = [-1,0,0,1]
        dys = [0,-1,1,0]
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            if CanGo(nx,ny,val):
                visited[nx][ny] = True
                q.append((nx,ny))
                if curMax < grid[nx][ny]:
                    curMax = grid[nx][ny]
                    curX, curY = nx, ny
                elif curMax == grid[nx][ny]:
                    if (curX > nx) or (curX == nx and curY > ny):
                        curX, curY = nx, ny

    return (curX, curY)


# k번 반복해서 움직이기
for _ in range(k):
    InitializeVisited()
    visited[r][c] = True
    q.append((r,c))
    new_x, new_y = bfs(grid[r][c])
    if new_x == -1 and new_y == -1:
        break
    else:
        r, c = new_x, new_y

print(r+1, c+1)