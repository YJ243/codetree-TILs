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
def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x, y, val):
    return InRange(x,y) and not visited[x][y] and grid[x][y] == val

def dfs(x,y,val):
    global cur_block
    for d in range(4):
        nx,ny = x+dirs[d][0], y+dirs[d][1]
        if CanGo(nx,ny,val):
            cur_block += 1
            visited[nx][ny] = True
            dfs(nx,ny,val)

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            cur_block = 1
            visited[i][j] = True
            dfs(i,j,grid[i][j])

            if cur_block >= 4:
                bomb_cnt += 1
            if max_block < cur_block:
                max_block = cur_block


print(bomb_cnt, max_block)