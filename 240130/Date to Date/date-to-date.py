m1, d1, m2, d2 = tuple(map(int, input().split()))

num_of_day = [0, 31,28,31,30,31,30,31,31,30,31,30,31]

first, second = 0,0

for i in range(1, m1):
    first += num_of_day[i]
first += d1
for i in range(1, m2):
    second += num_of_day[i]
second += d2

print(second - first + 1)

''' 해설 풀이 '''
'''
# 변수 선언 및 입력
m1, d1, m2, d2 = tuple(map(int, input().split()))

def num_of_days(m, d):
    # 계산 편의를 위해 월마다 몇 일이 있는지를 적어주기
    days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    total_days = 0

    # 1월부터 (m-1)월까지는 전부 꽉 채워져 있음
    for i in range(1, m):
        total_days += days[i]
    
    # m월의 경우에는 정확히 d일만 있음
    total_days += d

    return total_days

# 출력
total_days = num_of_days(m2, d2) - num_of_days(m1, d1) + 1
print(total_days)
'''