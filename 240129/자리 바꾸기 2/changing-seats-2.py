n, k = map(int, input().split())    # n: 1부터 n까지의 번호표, k: 자리 바꾸는 횟수
change_seats = [list(map(int, input().split())) for _ in range(k)]  # 자리 바꾸는 위치들

seats_cnt = [set() for _ in range(n+1)]    # seats_cnt[i]: i번 번호표 사람이 움직인 자리들 hashSet

seats = [0]     # seats[i]: i번 위치에 앉아있는 사람 번호
for i in range(1,n+1):
    seats.append(i)
    seats_cnt[i].add(i)

for _ in range(3):
    for a, b in change_seats:
        # seats[a]에 있는 사람은 b자리로, seats[b]에 있는 사람은 a자리로 감
        seats_cnt[seats[a]].add(b)
        seats_cnt[seats[b]].add(a)
        tmp = seats[b]
        seats[b] = seats[a]
        seats[a] = tmp

for i in range(1, n+1):
    print(len(seats_cnt[i]))