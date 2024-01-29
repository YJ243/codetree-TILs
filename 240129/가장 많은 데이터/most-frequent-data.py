# 변수 선언 및 입력:
n = int(input())
color_to_freq = dict()

max_cnt = 0

# 각 문자열이 몇 번씩 나왔는지를 hashmap에 기
for _ in range(n):
    color = input()
    # 이미 나와있던 문자열이라면 1을 더해주기
    if color in color_to_freq:
        color_to_freq[color] += 1
    # 처음 나온 문자열이라면 1을 직접 적어주기
    else:
        color_to_freq[color] = 1
    
    # 가장 많이 나온 횟수를 갱신
    max_cnt = max(max_cnt, color_to_freq[color])

print(max_cnt)