from collections import deque

n = int(input())
r1, c1, r2, c2 = map(int, input().split())

q = deque()
graph = [[0 for _ in range(n)] for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]
step = [[0 for _ in range(n)] for _ in range(n)]

dxs, dys = [-2,-1,1,2,2,1,-1,-2], [-1,-2,-2,-1,1,2,2,1]

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x, y):
    return InRange(x, y) and not visited[x][y]

def Push(x, y, val):
    step[x][y] = val
    visited[x][y] = True
    q.append((x,y))

def bfs():
    while q:
        x, y = q.popleft()
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            if CanGo(nx, ny):
                Push(nx, ny, step[x][y] + 1)

Push(r1-1, c1-1,0)
bfs()

if visited[r2-1][c2-1]:
    print(step[r2-1][c2-1])
else:
    print(-1)