from collections import deque

N = int(input())    # 숫자 N이 주어짐

q = deque()
cnt = 0
step = [0 for _ in range(2*N+1)]
visited = [ False for _ in range(2*N+1)]

def Push(num, operation_cnt):
    visited[num] = True
    step[num] = operation_cnt
    q.append(num)

def MakeOne():
    global cnt
    while q:
        cur = q.popleft()
        #print(cur)
        if cur == 1:    # 만약 숫자 1이 나왔다면 cnt 업데이트하고 반복문 나가기
            cnt = step[cur]
            break

        # 이제 4가지 연산을 사용할 수 있는지 보기
        if cur % 2 == 0 and (not visited[cur//2] or (step[cur]+1 < step[cur//2] and visited[cur//2])):
            # 만약 2로 나누어떨어진다면
            #print(1, cur//2)
            Push(cur//2, step[cur]+1)
        if cur % 3 == 0 and (not visited[cur//3] or (step[cur]+1 < step[cur//3] and visited[cur//3])):
            #print(2, cur//3)
            Push(cur // 3, step[cur]+1)
        if not visited[cur+1] or step[cur]+1 < step[cur+1]:
            #print(3, cur+1)
            Push(cur+1, step[cur]+1)
        if not visited[cur-1] or (step[cur]+1 < step[cur-1] and visited[cur-1]):
            #print(4, cur-1)
            Push(cur-1, step[cur]+1)

        #for i in range(1, 14):
            #print(i, step[i], visited[i])
        
            

Push(N, 0)
MakeOne()
print(cnt)