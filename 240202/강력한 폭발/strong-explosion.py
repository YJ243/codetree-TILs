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

def InRange(x,y):   # 범위 안에 있는지 확인하는 함수
    return 0 <= x and x < n and 0 <= y and y < n

def do_bomb():      # 초토화시키기
    global ans
    tmp = [[0 for _ in range(n)] for _ in range(n)]     # 임시 변수에 폭탄을 터뜨린 결과 저장
    for i in range(bomb_cnt):                           # tmp배열에 폭탄을 놓을 위치 표시하기
        bombX, bombY = bomb_loc[i][0], bomb_loc[i][1]
        tmp[bombX][bombY] = 1

    for i in range(bomb_cnt):       # 폭탄을 놓을 위치에 대해서
        x, y = bomb_loc[i]          # 현재 놓으려는 폭탄의 중심부
        bomb_idx = selected[i]      # Backtracking으로 선택한 폭탄 인덱스
        for j in range(4):          # 4개의 방향에 대해 확인하기
            nx, ny = x + bombed[bomb_idx][j][0], y+bombed[bomb_idx][j][1]
            if InRange(nx,ny):      # 범위안에 있다면 폭탄 놓기
                tmp[nx][ny] = 1

    curSum = 0          # 초토화되는 영역 개수
    for i in range(n):
        for j in range(n):
            curSum += tmp[i][j]

    ans = max(ans, curSum)  # 정답 업데이트


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

''' 해설 '''
'''
# 변수 선언 및 입력:
n = int(input())
bomb_type = [
    [0 for _ in range(n)]
    for _ in range(n)
]
bombed = [
    [False for _ in range(n)]
    for _ in range(n)
]

ans = 0

bomb_pos = list()

def in_range(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def bomb(x, y, b_type):
    # 폭탄 종류마다 터질 위치를 미리 정의하기
    bomb_shapes = [
        [],
        [[-2, 0], [-1, 0], [0, 0], [1, 0], [2, 0]],
        [[-1, 0], [1, 0], [0, 0], [0, -1], [0, 1]],
        [[-1, -1], [-1, 1], [0, 0], [1, -1], [1, 1]]
    ]

    # 격자 내 칸에 대해서만 영역을 표시
    for i in range(5):
        dx, dy = bomb_shapes[b_type][i]
        nx, ny = x+dx, y+dy
        if in_range(nx,ny):
            bombed[nx][ny] = True

def calc():
    # Step1. 폭탄이 터진 위치를 표시하는 배열을 초기화시키기
    for i in range(n):
        for j in range(n):
            bombed[i][j] = False
    
    # Step2.  각 폭탄의 타입에 따라 초토화되는 영역을 표시
    for i in range(n):
        for j in rnage(n):
            if bomb_type[i][j]:
                bomb(i,j,bomb_type[i][j])

    # Step3. 초토화된 영역의 수를 구하기
    cnt = 0
    for i in range(n):
        for j in range(n):
            if bombed[i][j]:
                cnt += 1
    return cnt

def find_max_area(cnt):
    global ans

    if cnt == len(bomb_pos):
        ans = max(ans, clac())
        return
    
    for i in range(1,4):
        x, y = bomb_pos[cnt]

        bomb_type[x][y] = i
        find_max_area(cnt+1)
        bomb_type[x][y] = 0

for i in range(n):
    given_row = list(map(int, input().split()))
    for j, bomb_place in enumerate(given_row):
        if bomb_place:
            bomb_pos.append((i,j))

find_max_area(0)
print(ans)
'''