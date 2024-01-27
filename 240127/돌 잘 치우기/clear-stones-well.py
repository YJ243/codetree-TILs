from collections import deque

n, k, m = tuple(map(int, input().split())) # n: 격자 크기, k: 시작점 개수, m: 치워야 할 돌 개수
grid = [list(map(int, input().split())) for _ in range(n)]  # 0: 빈칸, 1: 돌
visited = [[False for _ in range(n)] for _ in range(n)]
q = deque()

stones = [ (i,j) for i in range(n) for j in range(n) if grid[i][j] ]
selected_stones = []
start_points = []
ans = 0
# 시작점 입력받기
for _ in range(k):
    r, c = tuple(map(int, input().split()))
    start_points.append((r-1,c-1))

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x, y):
    return InRange(x,y) and not visited[x][y] and not grid[x][y]

def Initialize_visited():
    for i in range(n):
        for j in range(n):
            visited[i][j] = False
    

def bfs():
    while q:
        x, y = q.popleft()
        dxs = [-1,1,0,0]
        dys = [0,0,-1,1]
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            if CanGo(nx,ny):
                visited[nx][ny] = True
                q.append((nx,ny))

def Move():
    global ans
    Initialize_visited()
    # 돌 치우기
    for s in selected_stones:
        grid[s[0]][s[1]] = 0
    for start in start_points:
        visited[start[0]][start[1]] = True
        q.append(start)
    
    bfs()
    curr = sum([1 for i in range(n) for j in range(n) if visited[i][j]])
    ans = max(curr, ans)
    
    # 돌 원래대로
    for s in selected_stones:
        grid[s[0]][s[1]] = 1

# m개의 돌 조합 구하기
def Choose(idx, cnt):
    if(idx == len(stones)):
        if cnt == m:
            Move()
            return
        else:
            return

    if(cnt == m):
        Move()
        return
    
    selected_stones.append(stones[idx])
    Choose(idx+1, cnt+1)
    selected_stones.pop()

    Choose(idx+1, cnt)

Choose(0,0)

print(ans)