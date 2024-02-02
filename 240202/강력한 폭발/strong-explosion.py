n = int(input())    # 격자 크기

grid = [list(map(int, input().split())) for _ in range(n)]  # 격자 입력받기
ans = 0             # 가장 많이 폭발에 영향을 받은 개수
bomb_loc = []       # 폭탄이 있는 위치 담기
bomb_cnt = 0        # 폭탄 개수
for i in range(n):
    for j in range(n):
        if grid[i][j]:
            bomb_loc.append((i,j))
            bomb_cnt += 1

bombed = [      # 폭탄 종류에 따라 초토화시킬 영역
    [(-2,0),(-1,0),(1,0),(2,0)],
    [(-1,0),(1,0),(0,-1),(0,1)],
    [(-1,-1),(-1,1),(1,-1),(1,1)]
]

selected = []   # 선택된 폭탄들

def InRange(x,y):
    return 0 <= x and x < n and 0 <= y and y < n

def do_bomb():
    global ans
    tmp = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(bomb_cnt):
        bombX, bombY = bomb_loc[i][0], bomb_loc[i][1]
        tmp[bombX][bombY] = 1

    for i in range(bomb_cnt):
        x, y = bomb_loc[i]
        bomb_idx = selected[i]
        for j in range(4):
            nx, ny = x + bombed[bomb_idx][j][0], y+bombed[bomb_idx][j][1]
            if InRange(nx,ny):
                tmp[nx][ny] = 1

    curSum = 0
    for i in range(n):
        for j in range(n):
            curSum += tmp[i][j]

    ans = max(ans, curSum)


def Choose(idx):    # idx번째 폭탄을 선택하는 함수
    if idx == bomb_cnt:
        do_bomb()   # 폭탄을 놓고 초토화시키기

        return

    for i in range(3):  # 3종류의 폭탄 중 하나 선택
        selected.append(i)
        Choose(idx+1)
        selected.pop()

Choose(0)
print(ans)