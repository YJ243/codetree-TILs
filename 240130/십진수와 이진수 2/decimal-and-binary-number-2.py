# 변수 선언 및 입력
binary = list(map(int, input()))

# 십진수로 변환합니다.
num = 0
for b in binary:
    num = num*2 + b

# 십진수에 17을 곱합니다.
num *= 17

digit = []
# 이진수로 변환합니다.
while True:
    if num < 2:
        digit.append(num)
        break
    
    digit.append(num % 2)
    num //= 2

# 이진수를 출력 합니다.
# 뒤집은 다음에 출력해야 함에 유의합니다.
for d in digit[::-1]:
    print(d, end='')