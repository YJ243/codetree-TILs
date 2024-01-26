import sys
sys.setrecursionlimit(10**4) # sys.setrecursionlimit(2500)

# 변수 선언 및 입력
n, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False for _ in range(m)] for _ in range(n)]
dirs = ((1,0),(0,1),(-1,0),(0,-1))

# 주어진 위치가 격자를 벗어나는지 여부를 반환
def InRange(x,y):
    return 0 <= x and x < n and 0 <= y and y < m

# 주어진 위치로 이동할 수 있는지 여부를 확인
def CanGo(x,y,val):
    return InRange(x,y) and not visited[x][y] and grid[x][y] > val 

# visited 배열을 초기화해줌
def Initialize():
    for i in range(n):
        for j in range(m):
            visited[i][j] = False

max_safe = -1
height = 0

def dfs(x,y,k):
    # 네 방향 각각에 대하여 dfs 탐색 하
    for d in range(4):
        nx, ny = x+dirs[d][0], y+dirs[d][1]
        if CanGo(nx,ny,k):
            visited[nx][ny] = True
            dfs(nx,ny,k)

for k in range(1,101):
    # 새로운 탐색을 시작한다는 의미로 현재 안전영역 개수 0으로 갱신
    # visited 배열 초기화
    cur_safe = 0
    Initialize()

    # 격자의 각 위치에 대해 탐색을 시작할 수 있는 경우
    # 해당 위치로부터 시작한 dfs 탐색을 수행
    for i in range(n):
        for j in range(m):
            if CanGo(i,j,k):
                # 해당 위치를 탐색할 수 있는 경우
                # visited 배열을 갱신하고 안전영역을 하나 추
                cur_safe += 1
                visited[i][j] = True
                dfs(i,j,k)
    # 기존의 최대 영역의 수보다 클 경우 이를 갱신하고 인덱스를 저
    if max_safe < cur_safe:
        max_safe = cur_safe
        height = k


print(height, max_safe)