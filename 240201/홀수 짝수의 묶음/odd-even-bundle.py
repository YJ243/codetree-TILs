n = int(input())
arr = list(map(int, input().split()))
odd, even = 0,0

for num in arr:
    if num % 2 == 0:
        even += 1
    else:
        odd += 1

group_num = 0

while True:
    if group_num % 2 == 0:
        # 짝수를 만드는 차례
        if even:
            even -= 1
            group_num += 1
        elif odd >= 2:
            odd -= 2
            group_num += 1
        else:
            # 짝수를 만들어야 하는데 만들 숫자가 없는 상황
            # ex) ... + 짝 + 홀 + ( )
            if odd > 0: # 만약 홀수가 한개 남아 있다면 짝+홀+홀수1개 합쳐서 짝 만들어야 함
                group_num -= 1
                break
    else:
        # 홀수를 만드는 차례
        if odd:
            odd -= 1
            group_num += 1
        else:
            # 만약 홀수를 만들어야 하는데 홀수가 없는 상황
            # ex) ... + 짝 + 홀 + 짝 + (  )
            # 그럼 여기서 뭘 더 할 수가 없으니 나가기
            break
print(group_num)