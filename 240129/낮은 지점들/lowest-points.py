n = int(input())

x_to_min_y = dict()

for _ in range(n):
    x, y = map(int, input().split())
    if x not in x_to_min_y:
        x_to_min_y[x] = y
    else:
        if y < x_to_min_y[x]:
            x_to_min_y[x] = y

ans = 0
for key, value in x_to_min_y.items():
    ans += value
    
print(ans)

''' 해설 '''
'''
# 변수 선언 및 입력:
n = int(input())
min_y = dict()

# 각 x마다 최소 y만 저장해주기
for _ in range(n):
    x, y = tuple(map(int, input().split()))

    # 아직 map에 해당 x가 없다면 y값을 그대로 넣어주기
    if x not in min_y:
        min_y[x] = y
    # 그렇지 않다면, 최소 y를 넣어주기
    else:
        min_y[x] = min(min_y[x], y)

# 답을 저장하기
sum_val = 0

# map에 들어있는 값들을 순회
for value in min_y.values():
    # value에 해당하는 y값을 더해주기
    sum_val += value

print(sum_val)
'''