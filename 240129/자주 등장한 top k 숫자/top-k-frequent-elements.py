# 변수 선언 및 입력:
n, k = map(int, input().split())
arr = list(map(int, input().split()))

freq = dict()

# 각 숫자가 몇 번씩 나왔는지를
# hashmap에 기록하기
for num in arr:
    if num not in freq:
        freq[num] = 1
    else:
        freq[num] += 1

sorted_freq = sorted(freq.items(), key=lambda x: (-x[1], -x[0]))


for i in range(k):
    print(sorted_freq[i][0], end=' ')

''' 해설 '''
'''
# hashmap을 순회하며 중복되지 않게 새 배열을 만들어 주기
new_arr = [
    [value, key] for key, value in count.items()
]

# 문제에서 요구한 정렬 기준에 맞추어 정렬하기
new_arr = sorted(new_arr)

# 출력:
leng = len(new_arr)
for i in range(leng-1, leng-k-1, -1):
    print(new_arr[i][1], end=' ')
'''