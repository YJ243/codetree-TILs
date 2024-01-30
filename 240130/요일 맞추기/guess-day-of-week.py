# 입력
m1, d1, m2, d2 = tuple(map(int, input().split()))

day_of_week = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def count_days(m, d):
    # 2011년 1월 1일 부터 2011년 m월 d일까지 날짜수 세기
    total_days = 0
    for i in range(1,m):
        total_days += days[i]
    total_days += d
    return total_days

days_left = count_days(m2,d2) - count_days(m1, d1)


if days_left < 0:
    while days_left < 0:
        days_left += 7


cur_idx = days_left % 7

print(day_of_week[cur_idx])