from collections import deque

n, k, u, d = tuple(map(int, input().split()))   # n: 격자 크기, k: 도시 개수, 높이가 u이상 d이하
grid = [list(map(int, input().split())) for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]
dxs, dys = [-1,1,0,0], [0,0,-1,1]
ans = 0

q = deque()

selected_city = []

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(nx, ny):
    return InRange(nx, ny) and not visited[nx][ny] and u <= grid[nx][ny] and grid[nx][ny] <= d

def bfs():
    while q:
        x, y = q.popleft()
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            if CanGo(nx,ny):
                visited[nx][ny] = True
                q.append((nx,ny))
            
    

def Initialize():
    for i in range(n):
        for j in range(n):
            visited[i][j] = False   # 방문 배열 초기화
    
    for s in selected_city:         # 선택된 도시들을 시작점으로 하기 위해 큐에 넣기
        visited[s[0]][s[1]] = True
        q.append((s))



def Move():
    global ans
    Initialize()
    bfs()
    
    cur = sum([ 1 for i in range(n) for j in range(n) if visited[i][j]])
    ans = max(ans, cur)

def Choose(x, y, cnt):      # (x,y) idx번째 도시를 선택하는지 결정하는 함수, 이제까지 cnt개를 선택함
    if(cnt == k):
        Move()
        return

    for i in range(x, n):
        # y 값 초기화: 첫 번째 행(i == x)에서는 현재 y부터, 그 외에는 0부터 시작
        startY = y if i == x else 0
        for j in range(startY, n):
            selected_city.append((i, j))
            Choose(i, j+1, cnt+1)  # 다음 위치를 업데이트
            selected_city.pop()


Choose(0,0,0)
print(ans)