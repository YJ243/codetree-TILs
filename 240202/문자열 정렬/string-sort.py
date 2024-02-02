# 변수 선언 및 입력
# 예 : banana
inp = input()

# 각 문자를 원소로 담는 리스트 만들기
# 예 : ['b', 'a', 'n', 'a', 'n', 'a']
sorted_arr = sorted(inp)

# 각 문자를 원소로 갖는 리스트를 하나의 문자열로 합치기
# 예 : 'banana'
sorted_str = ''.join(sorted_arr)

# 출력
print(sorted_str)