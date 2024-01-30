a, b, c = tuple(map(int, input().split()))

days = a-11
if days < 0:
    print(-1)
    exit(0)

total = days*24*60  # 24시간 * days 가 지남

mins = (b-11)*60 + (c-11)   # 11시 11분에서 b시 c분까지의 시간 구하기

if mins < 0:
    print(-1)
    exit(0)

total += mins

print(total)