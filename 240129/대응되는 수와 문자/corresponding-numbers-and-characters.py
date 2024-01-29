n, m = map(int, input().split())
string_to_num = dict()
num_to_string = [0]
for i in range(1,n+1):
    string = input()
    string_to_num[string] = i
    num_to_string.append(string)

for _ in range(m):
    string = input()
    # 만약 이 string이 숫자라면
    if string.isdigit():
        print(num_to_string[int(string)])
    
    # 만약 이 string이 문자열이라면
    else:
        print(string_to_num[string])