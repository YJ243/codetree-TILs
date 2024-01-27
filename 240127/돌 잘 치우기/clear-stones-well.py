from collections import deque

# 변수 선언 및 입력
n, k, m = tuple(map(int, input().split())) # n: 격자 크기, k: 시작점 개수, m: 치워야 할 돌 개수
grid = [list(map(int, input().split())) for _ in range(n)]  # 0: 빈칸, 1: 돌

ans = 0
start_points = []
stones = [ (i,j) for i in range(n) for j in range(n) if grid[i][j] ]
selected_stones = []

# bfs에 필요한 변수들
q = deque()
visited = [[False for _ in range(n)] for _ in range(n)]

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x, y):
    return InRange(x,y) and not visited[x][y] and not grid[x][y]

def Initialize_visited():
    for i in range(n):
        for j in range(n):
            visited[i][j] = False
    
def bfs():
    # queue에 남은 것이 없을때까지 반복합니다.
    while q:
        # queue에서 가장 먼저 들어온 원소를 뺍니다.
        x, y = q.popleft()

        dxs = [-1,1,0,0]
        dys = [0,0,-1,1]
        # queue에서 뺀 원소의 위치를 기준으로 4방향을 확인해봅니다.
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            # 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            # 새로 queue에 넣어주고 방문 여부를 표시해줍니다. 
            if CanGo(nx,ny):
                visited[nx][ny] = True
                q.append((nx,ny))

def Move():
    global ans
    Initialize_visited()
    # 돌 치우기
    for s in selected_stones:
        grid[s[0]][s[1]] = 0
    
    # k개의 시작점을 queue에 넣고 시작합니다.
	# BFS는 여러 시작점에서 시작하여
    # 이동 가능한 칸을 전부 탐색하는 것이 가능합니다.
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
def Choose(idx, cnt):       # idx는 현재 stones 에서 선택할 시작점, cnt번째 돌을 고르는 함
    if cnt == m:
        Move()
        return
    
    for i in range(idx, len(stones)):
        selected_stones.append(stones[idx])
        Choose(idx+1, cnt+1)
        selected_stones.pop()

# 시작점 입력받기
for _ in range(k):
    r, c = tuple(map(int, input().split()))
    start_points.append((r-1,c-1))

Choose(0,0)
print(ans)