n, k, T =  input().split()
n = int(n)
k = int(k)
arr = []

for _ in range(n):
    inp = input()
    if inp.startswith(T):
        arr.append(inp)

arr = sorted(arr)
print(arr[k-1])

''' 해설 '''
'''
# 변수 선언 및 입력
n, k, t = tuple(input().split())
n, k = int(n), int(k)

# a가 b로 시작하는지 확인
def starts_with(a,b):
    # b의 길이가 더 길 수 없음
    if len(a) < len(b):
        return False

    # b의 길이만큼 살펴보며, a와 문자열이 완벽히 동일한지 확인
    return a[:len(b)] == b

words = []
for _ in range(n):
    word = input()
    if starts_with(word, t):
        words.append(word)

# 정렬을 진행
words.sort()

print(words[k-1])
'''