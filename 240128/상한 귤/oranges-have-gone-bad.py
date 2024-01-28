from collections import deque
n, k = tuple(map(int, input().split()))     # 격자 크기 n, 초기 상해잇는 귤 개수 k
grid = [list(map(int, input().split())) for _ in range(n)]



temp = [row[:] for row in grid]             # 중간에 정보를 저장하는 임시 격자

q = deque()     # bfs 탐색을 위한 큐
visited = [[False for _ in range(n)] for _ in range(n)]     # 방문했는지 확인
step = [[-1 for _ in range(n)] for _ in range(n)]           # 초기 상해있는 귤로부터 상하는데 걸리는 시간
cur_rotten = 0

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(nx,ny, px, py):   # 범위 안에 있고 방문하지 않았으며, 그 이전 위치가 2인 경우
    return InRange(nx,ny) and not visited[nx][ny] and grid[px][py] == 2

def Push(x, y, val):
    step[x][y] = val
    visited[x][y] = True
    q.append((x,y))

def bfs():
    global cur_rotten
    cur_rotten = -1
    while q:
        x, y = q.popleft()      # 현재 보고 있는 좌표
        # 상하좌우 네 방향 확인하기
        dxs, dys = [1,0,-1,0], [0,1,0,-1]
        
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy     # 다음 좌표
            if InRange(nx,ny) and not visited[nx][ny]:      # 만약 범위 안에 있다면
                if grid[nx][ny] == 2:   # 근데 그 다음 값이 2라면
                    visited[nx][ny] = True  # 방문 표시
                    q.append((nx,ny))
                elif grid[nx][ny] == 1:
                    if CanGo(nx,ny, x, y):
                        Push(nx,ny, step[x][y]+1)
                        temp[nx][ny] = 2
                        cur_rotten += 1

def Make_spoil():
    global grid
    while(True):
        # 만약 현재 턴에서 상한 귤 수가 0이라면
        if cur_rotten == -1:
            break;  # 더이상 상할 귤이 없으니 break
        
        rotted = [(i,j) for i in range(n) for j in range(n) if grid[i][j] == 2]

        # 먼저 k개의 상한 귤을 큐에 넣기
        for r in rotted:
            if step[r[0]][r[1]] == -1:
                Push(r[0], r[1], 0)
            else:
                Push(r[0], r[1], step[r[0]][r[1]])

        # 그 다음 bfs()탐색 수행
        bfs()

        # temp를 grid로 옮기기
        grid = [row[:] for row in temp]


Make_spoil()
for i in range(n):
    for j in range(n):
        if grid[i][j] == 1 and not visited[i][j]:
            step[i][j] = -2

for i in range(n):
    for j in range(n):
        print(step[i][j], end= ' ')
    print()