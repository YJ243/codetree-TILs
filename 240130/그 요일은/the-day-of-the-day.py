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

ans = 0
diff = count_days(m2, d2) - count_days(m1, d1)      # m1월 d1일부터 m2월 d2일까지 몇 일이 지났는지 계산

if diff >= 7:                           # 만약 일주일을 넘었다면
    ans = diff // 7                     # 몇 번 반복됐는지 확인
    if diff % 7 >= day_of_week[day]:    # 나머지 처리
        ans += 1

else:
    if diff % 7 >= day_of_week[day]:    # 만약 일주일을 넘지 못했다면 날짜 계산해서 결과값 계산하기
        ans = 1

print(ans)

''' 해설 '''
'''
ans = 0
start_date = num_of_days(m1, d1)
end_date = num_of_days(m2, d2)
cur_day = day_of_week[day]

for date in range(start_Date, end_date+1):
    # 오늘의 요일이 A요일과 같다면 정답 추가
    if cur_day == day_of_week[day]:
        ans += 1
    cur_da = (cur_day+1) % 7

# 출력
print(ans)
'''