a, b = map(int, input().split())
n = list(map(int,input()))

num = 0     # 10진수

for digit in n:
    num = num*a + digit

digit = []

while True:
    if num < b:
        digit.append(num)
        break
    
    digit.append(num % b)
    num //= b

for d in digit[::-1]:
    print(d, end='')