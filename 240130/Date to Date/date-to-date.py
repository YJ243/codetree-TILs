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