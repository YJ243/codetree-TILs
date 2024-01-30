binary = list(map(int, input()))

num = 0
for b in binary:
    num = num*2 + b
num *= 17

digit = []
while True:
    if num < 2:
        digit.append(num)
        break
    
    digit.append(num % 2)
    num //= 2

for d in digit[::-1]:
    print(d, end='')