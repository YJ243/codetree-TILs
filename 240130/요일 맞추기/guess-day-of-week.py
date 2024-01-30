# 변수 선언 및 입력
m1, d1, m2, d2 = tuple(map(int, input().split()))

def count_days(m, d):
    # 2011년 1월 1일 부터 2011년 m월 d일까지 날짜수 세기
    # 계산 편의를 위해 월마다 몇 일이 있는지를 적어주기
    days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    total_days = 0

    # 1월부터 (m-1)월까지는 전부 꽉 채워져 있음
    for i in range(1,m):
        total_days += days[i]

    # m월의 경우에는 정확히 d일만 있음
    total_days += d

    return total_days

# 두 날짜간의 차이가 몇 일인지 구하기
days_left = count_days(m2,d2) - count_days(m1, d1)

# 음수인 경우에는, 양수로 넘겨 계산해주면 올바르게 계산이 됨
if days_left < 0:
    while days_left < 0:
        days_left += 7

# 알맞은 요일의 이름을 출력
day_of_week = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
cur_idx = days_left % 7

print(day_of_week[cur_idx])