m1, d1, m2, d2 = tuple(map(int, input().split()))
day = input()

day_of_week = {"Mon":0, "Tue":1, "Wed":2, "Thu":3, "Fri":4, "Sat":5, "Sun":6}

def count_days(m, d):
    days = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    total_days = 0
    for i in range(1, m):
        total_days += days[i]
    total_days += d

    return total_days

diff = count_days(m2, d2) - count_days(m1, d1)

ans = diff // 7 + 1

if diff % 7 <= day_of_week[day]:
    ans += 1

print(ans)