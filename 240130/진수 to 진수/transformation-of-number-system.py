a, b = map(int, input().split())
n = list(map(int,input()))

num = 0     # 10진수

for digit in n:
    num = num*a + digit

digit = []

# b진수로 변환하기
while True:
    if num < b:
        digit.append(num)
        break
    
    digit.append(num % b)
    num //= b

# 진수 배열을 뒤집어 b진수를 출력
for d in digit[::-1]:
    print(d, end='')