n, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]
visited = [[False for _ in range(m)] for _ in range(n)]
dirs = ((1,0),(0,1),(-1,0),(0,-1))

def InRange(x,y):
    return 0 <= x and x < n and 0 <= y and y < m

def CanGo(x,y,val):
    return InRange(x,y) and not visited[x][y] and grid[x][y] > val 

def Initialize():
    global visited
    for i in range(n):
        for j in range(m):
            visited[i][j] = False

max_safe = 0
height = 0

def dfs(x,y,k):
    for d in range(4):
        nx, ny = x+dirs[d][0], y+dirs[d][1]
        if CanGo(nx,ny,k):
            visited[nx][ny] = True
            dfs(nx,ny,k)

for k in range(1,101):
    cur_safe = 0
    Initialize()
    for i in range(n):
        for j in range(m):
            if CanGo(i,j,k):
                cur_safe += 1
                visited[i][j] = True
                dfs(i,j,k)
    if max_safe < cur_safe:
        max_safe = cur_safe
        height = k

print(height, max_safe)