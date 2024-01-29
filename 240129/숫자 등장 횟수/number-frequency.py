# 변수 선언 및 입력:
n, m = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

freq = dict()

# 각 숫자가 몇 번씩 나왔는지르 hashmap에 기록
for num in arr:
    # 처음 나온 ㅅ수자라면 1을 직접 적어주기
    if num in freq:
        freq[num] += 1
    # 이미 나와있던 숫자라면 1을 더하기
    else:
        freq[num] = 1

# m개의 질의에 대해 몇 번씩 나왔는지를 출력
key_num = list(map(int, input().split()))
for num in key_num:
    if num in freq:
        print(freq[num], end=' ')
    else:
        print(0, end=' ')