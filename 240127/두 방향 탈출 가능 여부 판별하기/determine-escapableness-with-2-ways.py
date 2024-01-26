# 변수 선언 및 입력
n, m = tuple(map(int, input().split()))

graph = [
    # 빈칸:1, 뱀:0
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [
    [0 for _ in range(m)] 
    for _ in range(n)
]
dirs = [[1,0],[0,1]] # 아래, 오른쪽

# 주어진 위치가 격자를 벗어나는지 여부를 반환
def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < m

# 주어진 위치로 이동할 수 있는지 여부를 확인
def CanGo(x, y):
    return InRange(x,y) and not visited[x][y] and graph[x][y]

def dfs(x,y):
    for i in range(2):
        nx, ny = x+dirs[i][0], y+dirs[i][1]
        if CanGo(nx,ny):
            visited[nx][ny] = 1
            dfs(nx,ny)

r,c = 0,0
visited[r][c] = 1
dfs(r,c)

print(visited[n-1][m-1])