# 변수 선언 및 입력:
n, m = map(int, input().split())
string_to_num = dict()
num_to_string = [0]
for i in range(1,n+1):
    string = input()
    string_to_num[string] = i       # 각 문자에 대응되는 숫자를 hashmap에
    num_to_string.append(string)    # 각 숫자에 대응되는 문자를 arry에 기록
'''
해설에서는 num_to_string을 
words = [
    input()
    for _ in range(n)
]
이렇게 입력받았고, 0번 index부터 저장시킴
'''
for _ in range(m):
    string = input()
    # 만약 이 string이 숫자라면
    if string.isdigit():
        print(num_to_string[int(string)])
    
    # 만약 이 string이 문자열이라면
    else:
        print(string_to_num[string])


'''
해설은 입력된 값이 숫자인지 문자인지 판단을 아래와 같이 함
if ord(word[0]) >= ord('0') and ord(word[0]) <= ord('9'):   # 아스키 코드가 문자'0'부터 문자'9'까지일 
    num = int(word)
'''