n = int(input())

arr = [input() for _ in range(n)]

ans = 0
count = dict()
for i in range(n):
    sorted_elem = ''.join(sorted(arr[i]))
    arr[i] = sorted_elem
    
    if arr[i] not in count:
        count[arr[i]] = 1
    else:
        count[arr[i]] += 1
    ans = max(ans, count[arr[i]])

print(ans)

''' 해설 '''
'''
# 같은 그룹에 속하는 단어들의 문자를 정렬하면 모두 같아지는 특징 이용하기!!!

# 변수 선언 및 입력:
n = int(input())

count = dict()

# 입력 문자열을 정렬한 뒤 map에 저장
for _ in range(n):
    inp = input()
    # 정렬을 하면 자동으로 타입이 배열으로 변경된다는 점을 주의
    inp = sorted(inp)

    # 배열을 다시 문자열으로 돌려놓기
    string = ""
    for elem in inp:
        string += elem
    if string in count:
        count[string] += 1
    else:
        count[string] = 1

# map을 순회하며 최대인 경우를 출력해주기
ans = 0

for key, value in count.items():
    if ans < value:
        ans = value

print(ans)
'''