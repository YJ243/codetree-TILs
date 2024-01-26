# 입력받기
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
dirs = [[1,0],[0,1],[-1,0],[0,-1]]

def InRange(x, y):
    return 0 <= x and x < n and 0 <= y and y < n

def CanGo(x, y):
    return InRange(x,y) and not visited[x][y] and graph[x][y]

def dfs(x,y):
    global person_cnt
    for i in range(4):
        nx, ny = x+dirs[i][0], y+dirs[i][1]
        if CanGo(nx,ny):
            person_cnt += 1
            visited[nx][ny] = True
            dfs(nx,ny)

for i in range(n):
    for j in range(n):
        if CanGo(i,j):  # 만약 방문하지 않았고, 사람이라면
            person_cnt = 1
            visited[i][j] = True
            dfs(i,j)
            people.append(person_cnt)
people.sort()
print(len(people))
for p in people:
    print(p)