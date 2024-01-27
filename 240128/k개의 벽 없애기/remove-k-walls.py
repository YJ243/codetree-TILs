from collections import deque

n, k = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]   # 0: 이동 가능, 1: 벽

r1, c1 = map(int, input().split())
r2, c2 = map(int, input().split())
r1, c1, r2, c2 = r1-1, c1-1, r2-1, c2-1

step = [[0 for _ in range(n)] for _ in range(n)]
q = deque()
visited = [[False for _ in range(n)] for _ in range(n)]

walls = [(i,j) for i in range(n) for j in range(n) if graph[i][j]]

selected_walls = []

def Initialize():
    for i in range(n):
        for j in range(n):
            visited[i][j] = False
            step[i][j] = 0

def Push(x, y, val):
    step[x][y] = val
    visited[x][y] = True
    q.append((x,y))

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x, y):
    return InRange(x,y) and not visited[x][y] and not graph[x][y]

def bfs():
    while q:
        x, y = q.popleft()
        dxs, dys = [-1,1,0,0], [0,0,-1,1]
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            if CanGo(nx,ny):
                Push(nx, ny, step[x][y] + 1)
ans = 300
def Move():
    global ans
    # k개의 벽 없애기 (1 -> 0)
    for s in selected_walls:
        graph[s[0]][s[1]] = 0

    # 방문배열, 스텝배열 초기화
    Initialize()
    Push(r1, c1, 0)
    bfs()

    if visited[r2][c2]:
        ans = min(ans, step[r2][c2])

    # k개의 벽 원래대로 (0 -> 1)
    for s in selected_walls:
        graph[s[0]][s[1]] = 1

def Choose(idx, cnt):
    if idx == len(walls):
        if cnt == k:
            Move()
            return
        else:
            return

    if cnt == k:
        Move()
        return
    
    selected_walls.append(walls[idx])
    Choose(idx+1, cnt+1)
    selected_walls.pop()

    Choose(idx+1, cnt)

Choose(0, 0)  # 함수 호출
if ans == 300:
    ans = -1

print(ans)