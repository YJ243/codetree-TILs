n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]

# 그래프 모양 입력받기
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

ans = 0

def dfs(vertex):
    global ans
    for curV in graph[vertex]:
        if not visited[curV]:
            visited[curV] = True
            ans += 1
            dfs(curV)

visited[1] = True
dfs(1)
print(ans)