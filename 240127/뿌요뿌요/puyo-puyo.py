n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]
visited = [[False for _ in range(n)] for _ in range(n)]
dirs = ((1,0),(0,1),(-1,0),(0,-1))

bomb_cnt = 0
max_block = 0
cur_block = 0

# 탐색하는 위치가 격자 범위 내에 있는지 여부를 반환
def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

# 탐색하는 위치로 움직일 수 있는지 여부를 반
def CanGo(x, y, val):
    return InRange(x,y) and not visited[x][y] and grid[x][y] == val

def dfs(x,y,val):
    global cur_block
    # 네 방향 각각에 대하여 DFS 탐색을 하기
    for d in range(4):
        nx,ny = x+dirs[d][0], y+dirs[d][1]
        if CanGo(nx,ny,val):
            # 블럭이 하나 추가됨
            cur_block += 1
            visited[nx][ny] = True
            dfs(nx,ny,val)

# 격자의 각 위치에서 탐색을 시작할 수 있는 경우
# 한 블럭에 대한 DFS 탐색을 수행
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            # 해당 블럭을 방문할 수 있는 경우 visited 배열을 갱신하고
            # 새로운 블럭을 탐색한다는 의미로 cur_block을 1로 갱신
            cur_block = 1
            visited[i][j] = True
            dfs(i,j,grid[i][j])

            # 한 블럭 묶음에 대한 탐색이 끝난 경우 답을 갱신하기
            if cur_block >= 4:
                bomb_cnt += 1
            
            max_block = max(max_block, cur_block)

print(bomb_cnt, max_block)