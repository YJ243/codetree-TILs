inp = list(input())
count = dict()

for e in inp:
    if e not in count:
        count[e] = 1
    else:
        count[e] += 1

ans = ""
for e in inp:
    if count[e] == 1:
        ans += e
        break

if ans == "":
    ans = "None"
print(ans)

''' 해설 '''
'''
import sys
# 변수 선언 및 입력:
string = input()

count = dict()

# 각 알파벳이 몇 번씩 나왔는지 hashmap에 기록
for elem in string:
    if elem in count:
        count[elem] += 1
    else:
        count[elem] = 1

# 문자열을 앞에서부터 순회하여
# 딱 1회만 등장한 알파벳 찾기
for elem in string:
    if count[elem] == 1:
        # 만약 그런 알파벳이 존재한다면,
        # 알파벳을 출력하고 프로그램 종료
        print(elem)
        sys.exit()

# 문자열을 전부 순회할 때까지 프로그램이 종료되지 않았으므로
# 그러한 문자가 없는 경우임
print("None")
'''