# 변수 선언 및 입력
n = int(input())
graph = [   # 1: 사람, 0: 벽
    list(map(int, input().split()))
    for _ in range(n)
]
visited = [
    [False for _ in range(n)]
    for _ in range(n)
]

people = []
person_cnt = 0
dirs = [[1,0],[0,1],[-1,0],[0,-1]]  # 아래, 오른쪽, 위, 왼쪽

# 주어진 위치가 격자를 벗어나는지 여부를 반환
def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

# 주어진 위치로 이동할 수 있는지 여부를 확인
def CanGo(x, y):
    return InRange(x,y) and not visited[x][y] and graph[x][y]

def dfs(x,y):
    global person_cnt

    # 네 방향 각각에 대하여 DFS 탐색을 하기
    for i in range(4):
        nx, ny = x+dirs[i][0], y+dirs[i][1]
        if CanGo(nx,ny):
            # 마을에 존재하는 사람을 한 명 추가해주기
            person_cnt += 1
            visited[nx][ny] = True
            dfs(nx,ny)

# 격자의 각 위치에서 탐색을 시작할 수 있는 경우
# 한 마을에 대한 DFS 탐색을 수행
for i in range(n):
    for j in range(n):
        if CanGo(i,j):  # 만약 방문하지 않았고, 사람이라면
            # 해당 위치를 방문할 수 있는 경우 visited 배열을 갱신하고
            # 새로운 마을을 탐색한다는 의미로 people_num을 1로 갱신
            person_cnt = 1
            visited[i][j] = True
            dfs(i,j)
            # 한 마을에 대한 탐색이 끝난 경우 마을 내의 사람 수를 저장
            people.append(person_cnt)

# 각 마을 내 사람의 수를 오름차순으로 정렬

people.sort()
print(len(people))

for p in people:
    print(p)