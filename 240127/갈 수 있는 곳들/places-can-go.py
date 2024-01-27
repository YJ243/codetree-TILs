from collections import deque

# 변수 선언 및 입력:
n, k = tuple(map(int, input().split())) # n: 격자 크기, k: 시작점 개수
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

# bfs에 필요한 변수들 입니다.
q = deque()
visited = [
    [False for _ in range(n)]
    for _ in range(n)
]

# 시작점을 모두 bfs queue에 넣습니다.
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
    # queue에 남은 것이 없을때까지 반복합니다.
    while q:
        x, y = q.popleft()
        # queue에서 뺀 원소의 위치를 기준으로 4방향을 확인해봅니다.
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            # 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            # 새로 queue에 넣어주고 방문 여부를 표시해줍니다. 
            if CanGo(nx, ny):
                visited[nx][ny] = True
                q.append((nx,ny))

# bfs를 진행합니다.
bfs()

ans = sum([
    1
    for i in range(n)
    for j in range(n)
    if visited[i][j]
])
print(ans)