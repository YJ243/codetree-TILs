n, m = tuple(map(int, input().split()))

pos_a = [0]
pos_b = [0]

curA = 0
for _ in range(n):
    t, d = input().split()
    t = int(t)
    for _ in range(t):
        if d == 'L':
            curA -= 1
            pos_a.append(curA)
        else:
            curA += 1
            pos_a.append(curA)

curB = 0
for _ in range(m):
    t, d = input().split()
    t = int(t)
    for _ in range(t):
        if d == 'L':
            curB -= 1
            pos_b.append(curB)
        else:
            curB += 1
            pos_b.append(curB)


if len(pos_a) < len(pos_b):
    loc = pos_a[len(pos_a)-1]
    for _ in range(len(pos_b)-len(pos_a)):
        pos_a.append(loc)
    # a의 남은 부분을 마지막 원소로 채우기
elif len(pos_a) > len(pos_b):
    loc = pos_b[len(pos_b)-1]
    for _ in range(len(pos_a)-len(pos_b)):
        pos_b.append(loc)

ans = 0

for i in range(1,len(pos_a)-1):
    if pos_a[i] != pos_b[i] and pos_a[i+1] == pos_b[i+1]:
        ans += 1

print(ans)