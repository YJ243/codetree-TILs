from collections import deque

n, k = tuple(map(int, input().split())) # n: 격자 크기, k: 시작점 개수
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [
    [False for _ in range(n)]
    for _ in range(n)
]
q = deque()

# 시작점 위치 입력받기
for _ in range(k):
    r, c = map(int, input().split())
    q.append((r-1,c-1))
    visited[r-1][c-1] = True

def InRange(x,y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x,y):
    return InRange(x,y) and not visited[x][y] and grid[x][y] == 0

def bfs():
    dxs = [1,-1,0,0]
    dys = [0,0,1,-1]
    while q:
        x, y = q.popleft()
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            if CanGo(nx, ny):
                visited[nx][ny] = True
                q.append((nx,ny))


bfs()
ans = sum([
    1
    for i in range(n)
    for j in range(n)
    if visited[i][j]
])
print(ans)