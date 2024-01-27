import sys
from collections import deque

INT_MAX = sys.maxsize

# 변수 선언 및 입력
n, k = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]   # 0: 이동 가능, 1: 벽

r1, c1 = map(int, input().split())
r2, c2 = map(int, input().split())
r1, c1, r2, c2 = r1-1, c1-1, r2-1, c2-1

# bfs에 필요한 변수들 입니다.
q = deque()
step = [[0 for _ in range(n)] for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]

walls = [(i,j) for i in range(n) for j in range(n) if graph[i][j]]

selected_walls = []

ans = INT_MAX

def Initialize():
    for i in range(n):
        for j in range(n):
            visited[i][j] = False
            step[i][j] = 0

# queue에 새로운 위치를 추가하고
# 방문 여부를 표시해줍니다.
# 시작점으로 부터의 최단거리 값도 갱신해줍니다.
def Push(x, y, val):
    step[x][y] = val
    visited[x][y] = True
    q.append((x,y))

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

# 격자를 벗어나지 않으면서, 벽도 없고, 아직 방문한 적이 없는 곳이라면
# 지금 이동하는 것이 최단거리임을 보장할 수 있으므로 가야만 합니다. 
def CanGo(x, y):
    return InRange(x,y) and not visited[x][y] and not graph[x][y]

# bfs를 통해 최소 이동 횟수를 구합니다.
def bfs():
    # queue에 남은 것이 없을때까지 반복합니다.
    while q:
        # queue에서 가장 먼저 들어온 원소를 뺍니다.
        x, y = q.popleft()
        dxs, dys = [-1,1,0,0], [0,0,-1,1]

        # queue에서 뺀 원소의 위치를 기준으로 4방향을 확인해봅니다.
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            # 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            # 새로 queue에 넣어줍니다.
            if CanGo(nx,ny):
                # 최단 거리는 이전 최단거리에 1이 증가하게 됩니다. 
                Push(nx, ny, step[x][y] + 1)
def Move():
    global ans
    # k개의 벽 없애기 (1 -> 0)
    for s in selected_walls:
        graph[s[0]][s[1]] = 0

    # 방문배열, 스텝배열 초기화
    Initialize()
    # 시작점을 queue에 넣고 시작
    Push(r1, c1, 0)
    # bfs를 이용해 최소 이동 횟수를 구하
    bfs()
    # 도착점에 가는 것이 가능할때만
    # 답을 갱신해줍니다.
    if visited[r2][c2]:
        ans = min(ans, step[r2][c2])

    # k개의 벽 원래대로 (0 -> 1)
    for s in selected_walls:
        graph[s[0]][s[1]] = 1

def Choose(num):
    if len(selected_walls) == k:
        Move()
        return
    
    for i in range(num, len(walls)):
        selected_walls.append(walls[i])
        Choose(i+1)
        selected_walls.pop()

Choose(0)  # 함수 호출
if ans == INT_MAX:      # 불가능한 경우라면
    ans = -1            # -1를 답으로 넣어주기

print(ans)