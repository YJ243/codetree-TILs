import heapq
n = int(input())        # n명의 사람들

people = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):          # people[i]: (i번 번호표, arriveTime, stayTime)
    people[i].insert(0,i)

# 도착한 사람 순으로 보기 위해 arriveTime 기준으로 오름차순 정렬하기
people.sort(key=lambda x:x[1])
waiting_time = [0 for _ in range(n)]
waiting_pq = []     # 대기 우선순위 큐(번호표의 숫자가 작은 사람부터 나오도록)
exit_time = 0       # 정원에서 빠져나온 시간

# Step 1. 도착한 시간 순으로 확인
for i in range(n):
    idx, a, t = people[i][0], people[i][1], people[i][2]

    # 지금 도착한 사람의 도착시간이 exit_time보다 나중이라면
    # 예를 들어서 exit_time은 10이고 a는 1000이라면
    # 그 이전에 대기큐에 사람들이 있을 수 있음 
    # 그럼 그 사람들을 계속해서 큐에서 빼서 정원으로 보내주기
    # 언제까지? 대기큐안에 사람이 존재하면서 a가 exit_time보다 클 때까지
    # 만약 빠져나올 시간이 2000 이다. 그러면 더이상 못뺌, 왜냐면 지금 i번째꺼를 넣어주어야 하기 때문
    while a > exit_time and waiting_pq:
        cur_idx, cur_a, cur_t = heapq.heappop(waiting_pq)

        waiting_time[cur_idx] = exit_time - cur_a   # 대기 시간 업데이트
        exit_time += cur_t  # 현재 빠져나온 시간에 들어가서 cur_t동안 머무름

    
    # 큐에 들어있는 사람 될 수 있는대로 다 입장시켜주고 난 다음
    # 그래도 현재 도착 시간보다 exit_time이 더 뒤라면 바로 정원 입장시켜주기
    if a > exit_time:
        exit_time = a+t
        waiting_time[idx] = 0
    else:
        # 그렇지 않다면 즉 exit_time이 그 뒤로 밀려났다면
        # 큐에 삽입해주기
        heapq.heappush(waiting_pq, (idx, a, t))

# 끝나고 나서 만약 큐에 남아있을 경우 처리
while waiting_pq:
    cur_idx, cur_a, cur_t = heapq.heappop(waiting_pq)
    waiting_time[cur_idx] = exit_time - cur_a
    exit_time += cur_t


print(max(waiting_time))