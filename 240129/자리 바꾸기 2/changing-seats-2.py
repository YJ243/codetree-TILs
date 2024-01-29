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

''' 해설 '''
'''
# 입력:
n, k = tuple(map(int, input().split()))
change = [
    list(map(int, input().split()))
    for _ in range(k)
]

# 변수 선언
s = [set() for _ in range(n + 1)]
ans = [0 for _ in range(n + 1)]

# 시작 array를 arr에 표시합니다.
arr = [i for i in range(n + 1)]

for i in range(1, n + 1):
    # 각 i 숫자가 위치할 수 있는 자리를 HashSet에 넣어 저장합니다.
    s[i].add(i)
    ans[i] = 1

# 3k번 자리를 바꿉니다.
for _ in range(3):
    for (a, b) in change:
        # a와 b의 자리를 바꿔줍니다.
        # 이때 자리가 변화한 값은 arr[a]와 arr[b]밖에 없습니다.
        # 이 값들만 새로운 자리를 HashSet에 넣어 저장합니다.
        arr[a], arr[b] = arr[b], arr[a]

        if a not in s[arr[a]]:
            s[arr[a]].add(a)
            ans[arr[a]] += 1
        
        if b not in s[arr[b]]:
            s[arr[b]].add(b)
            ans[arr[b]] += 1

# 3k번 자리를 바꾸면서 각 숫자들이 위치할 수 있는 값들의 개수를 ans 배열에서 확인합니다.
for i in range(1, n + 1):
    print(ans[i])
'''