from collections import deque

NOT_EXISTS = (-1, -1)

n, k = tuple(map(int, input().split()))
grid = [list(map(int, input().split())) for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]

q = deque()

# 현재 위치
r, c = map(int, input().split())
r -= 1
c -= 1

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x,y,val):
    return InRange(x,y) and not visited[x][y] and grid[x][y] < val

# visited 배열을 초기화해줌
def InitializeVisited():
    for i in range(n):
        for j in range(n):
            visited[i][j] = False

def bfs(val):
    curMax, curX, curY = 0,-1,-1
    # BFS 탐색을 수행
    while q:
        x, y = q.popleft()
        dxs = [-1,0,0,1]
        dys = [0,-1,1,0]

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            if CanGo(nx,ny,val):
                visited[nx][ny] = True
                q.append((nx,ny))
                if curMax < grid[nx][ny]:
                    curMax = grid[nx][ny]
                    curX, curY = nx, ny
                elif curMax == grid[nx][ny]:
                    if (curX > nx) or (curX == nx and curY > ny):
                        curX, curY = nx, ny

    return (curX, curY)


# k번 반복해서 움직이기
for _ in range(k):
    InitializeVisited()
    visited[r][c] = True
    q.append((r,c))
    new_x, new_y = bfs(grid[r][c])
    if new_x == -1 and new_y == -1:
        break
    else:
        r, c = new_x, new_y

print(r+1, c+1)

''' 해설 풀이 '''
'''

import collections 

NOT_EXISTS = (-1, -1)

n, k = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

# 현재 위치
r, c = tuple(map(int, input().split()))

bfs_q = collections.deque()
visited = [
    [0 for _ in range(n)]
    for _ in range(n)
]

def in_range(x, y):
    return 0 <= x and x < n and 0 <= y and y < n


def can_go(x, y, target_num):
    return in_range(x, y) and not visited[x][y] and \
           grid[x][y] < target_num


# visited 배열을 초기화 해줍니다.
def initialize_visited():
    for i in range(n):
        for j in range(n):
            visited[i][j] = False

def bfs():
    dxs, dys = [0, 1, 0, -1], [1, 0, -1, 0]

    curr_x, curr_y = curr_cell
    visited[curr_x][curr_y] = True
    bfs_q.append(curr_cell)
    
    target_num = grid[curr_x][curr_y]
    
    # BFS 탐색을 수행합니다.
    while bfs_q:
        curr_x, curr_y = bfs_q.popleft()
        
        for dx, dy in zip(dxs, dys):
            new_x, new_y = curr_x + dx, curr_y + dy
            
            if can_go(new_x, new_y, target_num):
                bfs_q.append((new_x, new_y))
                visited[new_x][new_y] = True

# best 위치를 새로운 위치로 바꿔줘야 하는지를 판단
def need_update(best_pos, new_pos):
    # 첫 도달 가능한 위치라면 update가 필요
    if best_pos == NOT_EXISTS:
        return True
    
    best_x, best_y = best_pos
    new_x, new_y = new_pos

    # 숫자, -행, -열 순으로 더 큰 곳이 골라져야 함
    return (grid[new_x][new_y], -new_x, -new_y) > (grid[best_x][bext_y], -best_x, -best_y)

# 가장 우선순위가 높은 위치를 찾아 위치를 이동하기
def move():
    global curr_cell

    # BFS 탐색을 위한 초기화 작업을 수행합니다.
    initialize_visited()
    
    # Step1. BFS를 진행하여 갈 수 있는 모든 위치를 탐색합니다.
    bfs()

    # Step2. 
    # 도달 할 수 있는 위치들 중
    # 가장 우선순위가 높은 위치를 구합니다.
    best_pos = NOT_EXISTS
    for i in range(n):
        for j in range(n):
            # 도달이 불가능하거나 현재 위치는 건너뛰기
            if not visitd[i][j] or (i,j) == curr_cell:
                continue
            new_pos = (i,j)

            if need_update(best_pos, new_pos):
                best_pos = new_pos
    
    # Step 3. 위치를 이동하기

    # 만약 움직일 위치가 없다면 종료합니다.
    if best_pos == NOT_EXISTS:
        return False
    # 움직일 위치가 있다면 이동합니다.
    else:
        curr_cell = best_pos
        return True
    
# k번에 걸쳐 움직이는 것을 반복
for _ in range(k):
    is_moved = move()

    # 움직이지 못했다면 바로 종료하기
    if not is_moved:
        break

final_x, final_y = curr_cell
print(final_x+1, final_y+1)
'''