from collections import deque

n, g = tuple(map(int, input().split()))

not_invited = [ set() for _ in range(g) ]   # 각 그룹마다 초대받지 못한 사람들에 대한 HashSet
person_in_group = [[] for _ in range(n+1)]  # 각 사람이 속해있는 그룹들
invited = [False for _ in range(n+1)]
for group_num in range(g):
    inp = list(map(int, input().split()))
    for i in range(1, len(inp)):
        not_invited[group_num].add(inp[i])
        person_in_group[inp[i]].append(group_num)

q = deque()
invited[1] = True
q.append(1)

while q:
    cur_num = q.popleft()

    for group_num in person_in_group[cur_num]:
        not_invited[group_num].discard(cur_num)  # 현재 숫자를 해당 그룹에서 빼기
        
        if len(not_invited[group_num]) == 1:     # 만약 남은 원소가 한개라면
            cur = not_invited[group_num].pop()
            invited[cur] = True
            q.append(cur)


ans = sum(invited)
print(ans)